% Parameter settings
fs = 1000;  % Sampling rate
T = 2;      % Signal length (seconds)
N = fs * T; % Number of samples
t = 0:1/fs:(T-1/fs); % Time vector

% Signal frequencies
omega1 = 100 * pi;
omega2 = 150 * pi;

% Different noise variance values
sigma2_values = [0.01, 0.1, 1, 10];

% Number of independent runs
M = 100;

for i = 1:length(sigma2_values)
    sigma2 = sigma2_values(i);
    
    periodograms = zeros(M, N/2+1);
    
    for m = 1:M
        % Randomly generate interference frequency
        omegaI = 50*pi + (80*pi - 50*pi) * rand;
    
        % Generate signal
        x = sin(omega1 * t) + 2 * cos(omega2 * t) + 4 * cos(omegaI * t) + sqrt(sigma2) * randn(size(t));
    
        % Compute periodogram
        [Pxx, f] = my_periodogram(x, fs);
    
        % Save periodogram
        periodograms(m, :) = Pxx;
    end
    
    average_periodogram = mean(periodograms, 1);

    % Plot results
    figure;
    subplot(2,2,1);
    plot(f, 10*log10(periodograms(1, :)));
    title('Periodogram of 1st Run');
    xlabel('Frequency (Hz)');
    ylabel('Power/Frequency (dB/Hz)');
    
    subplot(2,2,2);
    plot(f, 10*log10(periodograms(50, :)));
    title('Periodogram of 50th Run');
    xlabel('Frequency (Hz)');
    ylabel('Power/Frequency (dB/Hz)');
    
    subplot(2,2,3);
    plot(f, 10*log10(periodograms(100, :)));
    title('Periodogram of 100th Run');
    xlabel('Frequency (Hz)');
    ylabel('Power/Frequency (dB/Hz)');
    
    subplot(2,2,4);
    plot(f, 10*log10(average_periodogram));
    title('Average Periodogram');
    xlabel('Frequency (Hz)');
    ylabel('Power/Frequency (dB/Hz)');
    sgtitle(['Noise Variance \sigma^2 = ', num2str(sigma2)]);
end

function [Pxx, f] = my_periodogram(x, fs)
    N = length(x);
    X = fft(x); % Use N-point FFT
    Pxx = (1/(fs*N)) * abs(X(1:N/2+1)).^2; % Take the first N/2+1 points of the FFT result
    Pxx(2:end-1) = 2*Pxx(2:end-1); % Double the values except for the DC and Nyquist components
    f = fs * (0:(N/2)) / N; % Generate vector for positive frequencies only
end