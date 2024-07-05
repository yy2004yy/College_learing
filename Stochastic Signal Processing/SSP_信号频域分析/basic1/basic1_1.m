clc
clear
% Parameter settings
fs = 1000; % Sampling rate
T = 2; % Signal duration
t = 0:1/fs:T-1/fs; % Time vector
f1 = 50;
f2 = 75;
sigma2 = 0.1;

% Generate signal
N = sqrt(sigma2) * randn(size(t)); % White Gaussian noise
x = sin(2 * pi * f1 * t) + 2 * cos(2 * pi * f2 * t) + N;

% Plot periodogram
figure;
subplot(1,2,1);
periodogram(x, rectwin(length(x)), [], fs); % Periodogram with rectangular window
title('Periodogram with Rectangular Window');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
sgtitle('Window Type Variation');

subplot(1,2,2);
periodogram(x, hamming(length(x)), [], fs); % Periodogram with Hamming window
title('Periodogram with Hamming Window');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');

% Analysis of parameter variations
% Change sampling rate
fs_high = 2000;
t_high = 0:1/fs_high:T-1/fs_high;
x_high = sin(2 * pi * f1 * t_high) + 2 * cos(2 * pi * f2 * t_high) + sqrt(sigma2) * randn(size(t_high));

figure;
subplot(1,2,1);
periodogram(x, rectwin(length(x)), [], fs); % Original sampling rate
title('Periodogram with Original Sampling Rate');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');

subplot(1,2,2);
periodogram(x_high, rectwin(length(x_high)), [], fs_high); % Higher sampling rate
title('Periodogram with Higher Sampling Rate');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
sgtitle('Sampling Rate Variation');

% Change signal length
T_long = 4;
t_long = 0:1/fs:T_long-1/fs;
x_long = sin(2 * pi * f1 * t_long) + 2 * cos(2 * pi * f2 * t_long) + sqrt(sigma2) * randn(size(t_long));

figure;
subplot(1,2,1);
periodogram(x, rectwin(length(x)), [], fs); % Original signal length
title('Periodogram with Original Signal Length');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');

subplot(1,2,2);
periodogram(x_long, rectwin(length(x_long)), [], fs); % Longer signal
title('Periodogram with Longer Signal Length');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
sgtitle('Signal Length Variation');

% Change noise variance
sigma2_high = 1;
x_high_noise = sin(2 * pi * f1 * t) + 2 * cos(2 * pi * f2 * t) + sqrt(sigma2_high) * randn(size(t));

figure;
subplot(1,2,1);
periodogram(x, rectwin(length(x)), [], fs); % Original noise variance
title('Periodogram with Original Noise Variance');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');

subplot(1,2,2);
periodogram(x_high_noise, rectwin(length(x_high_noise)), [], fs); % Higher noise variance
title('Periodogram with Higher Noise Variance');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
sgtitle('Noise Variance Variation');

% Change FFT length
nfft_short = 512;
nfft_long = 4096;

figure;
subplot(1,2,1);
periodogram(x, rectwin(length(x)), nfft_short, fs); % Short FFT length
title('Periodogram with Short FFT Length');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');

subplot(1,2,2);
periodogram(x, rectwin(length(x)), nfft_long, fs); % Long FFT length
title('Periodogram with Long FFT Length');
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
sgtitle('FFT Length Variation');
