% Parameter definition
fs = 1000;              % Sampling frequency 1 kHz
T = 4;                  % Signal duration 4 seconds
t = 0:1/fs:T-1/fs;      % Time vector
f1 = 60;                % Frequency of the first sinusoidal wave 60 Hz
f2 = 150;               % Frequency of the second cosine wave 150 Hz
N = length(t);          % Signal length
sigma = sqrt(0.1);      % Standard deviation of Gaussian white noise

% Generate Gaussian white noise
noise = sigma*randn(1,N); 

% Generate random signal
X = sin(2*pi*f1*t) + 2*cos(2*pi*f2*t) + noise;

% Calculate autocorrelation
Rxx = xcorr(X, 'coeff');

% Cross-correlation between the signal and Gaussian white noise
Rxn = xcorr(X, noise, 'coeff'); 

% Plot the signal
figure;
subplot(3,1,1);
plot(t, X);
title('Stochastic Signal X(t)');

% Plot the autocorrelation function
subplot(3,1,2);
plot(-N+1:N-1, Rxx);
title('Autocorrelation Rx(t)');

% Plot the cross-correlation function
subplot(3,1,3);
plot(-N+1:N-1, Rxn);
title('Cross-Correlation Rxn(t)');
