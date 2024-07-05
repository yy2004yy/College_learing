clc
clear
% Parameters
fs = 50000; % Sampling frequency (Hz)
f0 = 1000; % Initial frequency (Hz)
k = 12000; % Chirp rate (Hz/s)
T = 0.1; % Duration of the chirp signal (s)
t = 0:1/fs:T-1/fs; % Time vector

% Generate chirp signal
X = cos(2*pi*(f0*t + 0.5*k*t.^2));

% Matched filter: time-reversed complex conjugate of the chirp signal
matched_filter = fliplr(conj(X));

% Example of received signal with noise
SNR = 10; % Signal-to-noise ratio in dB
sigma = sqrt(mean(X.^2) / (10^(SNR / 10))); % Noise standard deviation
% t_shift = T + 0.3; % Example of a shifted time
t_shift = 0.11 + (1 - 0.11) * rand;
signal_length = round((t_shift + T) * fs);
Y = [zeros(1, round(t_shift*fs)), X, zeros(1, signal_length - length(X) - round(t_shift*fs))] + sigma * randn(1, signal_length);
% Y = [zeros(1, round(t_shift*fs) - length(X)), X] + sigma * randn(1, round(t_shift*fs));

% Apply matched filter
R = conv(Y, matched_filter, 'valid');

% Estimate end time
[~, max_idx] = max(R);
t_est = (max_idx - 1) / fs;
t_shift
t_est

% Plot received signal and matched filter output
figure;
subplot(2,1,1);
plot((0:length(Y)-1)/fs, Y);
title('Received Signal with Noise');
xlabel('Time (s)');
ylabel('Amplitude');

subplot(2,1,2);
plot((0:length(R)-1)/fs, R);
title('Output of Matched Filter');
xlabel('Time (s)');
ylabel('Amplitude');
hold on;
plot(t_est, max(R), 'ro');
legend('Matched Filter Output', 'Estimated End Time');
