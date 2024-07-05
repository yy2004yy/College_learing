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

% Signal-to-noise ratio (dB)
SNR = -0;

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
    window = Y(start_idx:end_idx);
    window_energies(i) = sum(window.^2);
end

% Find position of maximum energy
[~, max_idx] = max(window_energies);
t_end_est = (max_idx-1) * step / fs; % Estimated end time

% Display results
disp(['True End Time: ', num2str(t_shift), ' s']);
disp(['Estimated End Time: ', num2str(t_end_est), ' s']);

% Plot results
figure;
subplot(2,1,1);
plot((0:length(Y)-1)/fs, Y);
title('Received Signal');
xlabel('Time (s)');
ylabel('Amplitude');
hold on;
xline(t_shift, 'g', 'True End Time');
xline(t_end_est, 'r', 'Estimated End Time');
legend('Signal', 'True End Time', 'Estimated End Time');
hold off;

subplot(2,1,2);
plot((0:num_windows-1)*step/fs + T, window_energies);
title('Window Energies');
xlabel('Time (s)');
ylabel('Energy');
hold on;
xline(t_end_est, 'r', 'Estimated End Time');
legend('Window Energies', 'Estimated End Time');
hold off;
