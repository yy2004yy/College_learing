clc
clear
% Parameters
fs = 50000; % Sampling frequency (Hz) 
f0 = 1000; % Initial frequency (Hz) 
k = 12000; % Frequency slope (Hz/s) 
T = 0.1; % Duration of the linear frequency modulated signal (s) 
t = 0:1/fs:T-1/fs; % Time vector 

% Generate linear frequency modulated signal 
X = cos(2*pi*(f0*t + 0.5*k*t.^2));

% SNR range
SNR_values = -60:2:0;
num_SNR = length(SNR_values);
num_trials = 500;

% Initialize results 
MSE = zeros(num_SNR, 1);
Success_rate = zeros(num_SNR, 1);
success_threshold = 0.03; % Threshold for success rate success_threshold

for snr_idx = 1:num_SNR
    SNR = SNR_values(snr_idx);
    mse_accum = 0;
    success_count = 0;

    for trial = 1:num_trials
        % Generate received signal with noise 
        t_shift = 0.11 + (1 - 0.11) * rand; % True end time
        sigma = sqrt(mean(X.^2) / (10^(SNR / 10))); % Standard deviation of noise
        signal_length = round((t_shift + T) * fs);
        Y = [zeros(1, round(t_shift*fs)), X, zeros(1, signal_length - length(X) - round(t_shift*fs))] + sigma * randn(1, signal_length);

        % Window size and sliding step 
        window_length = T * fs; % Window size (0.1s)
        step = 1; % Step size (1 sample)

        % Compute energy for each window 
        num_windows = floor((length(Y) - window_length) / step) + 1;
        window_energies = zeros(num_windows, 1);

        for i = 1:num_windows
            start_idx = (i-1)*step + 1;
            end_idx = start_idx + window_length - 1;
            if end_idx > length(Y)
                break;
            end
            window = Y(start_idx:end_idx);
            window_energies(i) = sum(window.^2);
        end

        % Find position of maximum energy 
        [~, max_idx] = max(window_energies);
        t_end_est = (max_idx-1) * step / fs; % Estimated end time

        % Compute error 计算误差
        mse_accum = mse_accum + (t_end_est - t_shift)^2;
        if abs(t_end_est - t_shift) < success_threshold
            success_count = success_count + 1;
        end
    end

    % Compute mean squared error and success rate 
    MSE(snr_idx) = mse_accum / num_trials;
    Success_rate(snr_idx) = success_count / num_trials;
    snr_idx
end

% Display results 
disp('SNR (dB) | MSE       | Success Rate');
disp('-------------------------------');
for snr_idx = 1:num_SNR
    fprintf('%8d | %9.6f | %12.6f\n', SNR_values(snr_idx), MSE(snr_idx), Success_rate(snr_idx));
end

% Plot results 
figure;
subplot(2,1,1);
plot(SNR_values, MSE, '-o');
title('MSE vs SNR');
xlabel('SNR (dB)');
ylabel('MSE');
grid on;

subplot(2,1,2);
plot(SNR_values, Success_rate, '-o');
title('Success Rate vs SNR');
xlabel('SNR (dB)');
ylabel('Success Rate');
grid on;
sgtitle('Periodogram Method');