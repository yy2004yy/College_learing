clc
clear
% Parameters
fs = 50000; % Sampling frequency (Hz)
f0 = 1000; % Initial frequency (Hz)
k = 12000; % Chirp rate (Hz/s)
T = 0.1; % Duration of the linear frequency modulated signal (s)
t = 0:1/fs:T-1/fs; % Time vector

% Generate a linear frequency modulated signal
X = cos(2*pi*(f0*t + 0.5*k*t.^2));

% Matched filter: Time reversal and conjugate of the linear frequency modulated signal
matched_filter = fliplr(conj(X));

% Parameters
SNR_values = -40:2:-12; 
num_SNR = length(SNR_values);
MSE = zeros(num_SNR, 1); % Mean Squared Error
Success_rate = zeros(num_SNR, 1); % Success Rate
N = 500; % Number of runs

for snr_idx = 1:num_SNR
    SNR = SNR_values(snr_idx);
    sigma = sqrt(mean(X.^2) / (10^(SNR / 10))); % Standard deviation of noise
    t_estimates = zeros(N, 1); % Store the estimated end times for each run
    true_times = zeros(N, 1); % Store the true end times for each run
    
    for i = 1:N
        % Randomly generate true end time
        t_true = 0.11 + (1 - 0.11) * rand;
        true_times(i) = t_true;

        % Generate received signal with noise
        signal_length = round((t_true + T) * fs);
        Y = [zeros(1, round(t_true*fs)), X, zeros(1, signal_length - length(X) - round(t_true*fs))] + sigma * randn(1, signal_length);

        % Apply the matched filter
        R = conv(Y, matched_filter, 'valid');

        % Estimate the end time
        [~, max_idx] = max(R);
        t_est = (max_idx - 1) / fs;
        t_estimates(i) = t_est;
    end
    
    % Calculate MSE and success rate
    MSE(snr_idx) = mean((t_estimates - true_times).^2);
    Success_rate(snr_idx) = sum(abs(t_estimates - true_times) < 0.03) / N;
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
sgtitle('Matched Filter Method');