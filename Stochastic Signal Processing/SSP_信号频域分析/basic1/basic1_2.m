% Parameter settings
fs = 1000; % Sampling frequency (Hz)
T = 2;     % Signal duration (s)
t = 0:1/fs:T-1/fs; % Time vector
f1 = 50;   % Signal frequency 1 (Hz)
f2 = 75;   % Signal frequency 2 (Hz)
sigma2 = 0.1;

% Generate signal
x = sin(2 * pi * f1 * t) + 2 * cos(2 * pi * f2 * t) + sqrt(sigma2) * randn(size(t));

% Compute PSD using MATLAB's periodogram function
[Pxx_matlab_p, f_matlab_p] = periodogram(x, rectwin(length(x)), [], fs);

% Compute PSD using custom periodogram function
[Pxx_custom_p, f_custom_p] = my_periodogram(x, fs);

% Compute PSD using custom correlogram function
[Pxx_custom_c, f_custom_c] = my_correlogram(x, fs);

% Plotting
figure;

% Plot custom periodogram and MATLAB built-in periodogram
subplot(2, 1, 1);
plot(f_custom_p, 10*log10(Pxx_custom_p));
hold on;
plot(f_matlab_p, 10*log10(Pxx_matlab_p));
title('Periodogram (Positive Frequencies Only)');
xlabel('Frequency (Hz)');
ylabel('Power Spectral Density (dB/Hz)');
grid on;
legend('Custom Periodogram', 'MATLAB Periodogram');

% Plot custom correlogram and MATLAB's pwelch results
subplot(2, 1, 2);
plot(f_custom_c, 10*log10(abs(Pxx_custom_c)));
hold on;
plot(f_matlab_p, 10*log10(Pxx_matlab_p));
title('Correlogram Method');
xlabel('Frequency (Hz)');
ylabel('Power Spectral Density (dB/Hz)');
grid on;
legend('Custom Correlogram', 'MATLAB pwelch');

function [Pxx, f] = my_periodogram(x, fs)
    N = length(x);
    X = fft(x, N); % Use N-point FFT to ensure symmetric results
    Pxx = (1/N) * abs(X(1:N/2+1)).^2; % Take the first N/2+1 points of the FFT result, including the DC component
    f = fs * (0:N/2) / N; % Generate vector for positive frequencies only
end

function [Pxx, f] = my_correlogram(x, fs)
    % Compute PSD using the Correlogram method
    [Rxx, ~] = xcorr(x, 'biased'); % Compute the biased autocorrelation function

    % Compute the Fourier transform of the autocorrelation function
    Pxx = fft(Rxx);

    % Generate frequency vector for positive frequencies
    N = length(Rxx);
    
    % Retain only the positive part
    half_N = floor(N/2); % Ensure the index is an integer
    Pxx = Pxx(1:half_N+1);
    f = fs * (0:half_N) / N;
end


% % 自定义周期图函数
% function [Pxx, f] = myPeriodogram(x, fs)
%     N = length(x);
%     X = fft(x);
%     Pxx = (1/N) * abs(X).^2;
%     f = (0:(N-1)) * (fs/N);
% end

% % 自定义自相关图函数
% function [Pxx, f] = myCorrelogram(x, fs)
%     N = length(x);
%     Rxx = xcorr(x, 'biased');
%     Rxx = Rxx(N:end); % 只保留正频率部分
%     Rxx = Rxx / Rxx(1); % 归一化
%     X = fft(Rxx);
%     Pxx = abs(X);
%     f = (0:(N-1)) * (fs/(2*N));
% end


