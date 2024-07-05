clc
clear 

num_micro = 8;   % Number of microphones
c = 340;         % Speed of sound in air is 340m/s
d = 0.085;       % Spacing
N = 44100;       % Sampling frequency

% Read the original audio file
[sig_ori, FS] = audioread('test_audio.wav');
sig_ori = sig_ori'; % Transpose the signal matrix to make it a row vector
Len_sig = length(sig_ori); % Get the length of the signal
dt = 1/FS; % Sampling interval
t = 0:dt:Len_sig/FS; % Create a time vector
t = t(1:Len_sig); % Adjust the time vector to match the signal length

% Locations of eight microphones
Loc(1,:) = [0, 0, 0, 0, 0, 0, 0, 0];
Loc_M_x = Loc(1,:);
Loc(2,:) = zeros(1, num_micro);

for i = 1:num_micro
    Loc(2,i) = 0.085*i;
end
Loc_M_y = Loc(2,:);

% Calculate different directions of arrival (DOA) produced by different lags
num = 23;
lags = zeros(1, num);
theta = zeros(1, num);
for i = 1:num
    lags(i) = -11 + i - 1;
    theta(i) = asin(c*lags(i)/(N*d))*(180/pi);
end

% Loop for different SNR values
SNR_dB_values = [30, 10, -10];
num_iterations = 100;
correct_detection_percentages = zeros(length(SNR_dB_values), 1);
average_errors = zeros(length(SNR_dB_values), 1);

for snr_index = 1:length(SNR_dB_values)
    SNR_dB = SNR_dB_values(snr_index);
    errors = zeros(1, num_iterations);  % Array to store errors

    for iter = 1:num_iterations
        % Randomly select a theta for each iteration
        random_index = randi(numel(theta));
        random_theta = theta(random_index);

        sin_r_theta = sin(random_theta * pi / 180);

        t_d = d * sin_r_theta / c;
        real_lag = t_d * N;
        real_lag = round(real_lag);
        T_D = [11 + real_lag, 11];

        % Calculate SNR
        signal_power = sig_ori * sig_ori' / Len_sig;       % calculate signal power
        noise_power = signal_power / (10^(SNR_dB / 10));   % noise

        Signal_Received = [];
        for p = 1:2
            noise = sqrt(noise_power) * randn(1, Len_sig); 
            sig_noise = sig_ori + noise;
            Signal_with_noise = [sqrt(noise_power) * randn(1, T_D(p)), sig_noise, sqrt(noise_power) * randn(1, max(T_D) - T_D(p))]; 
            Signal_Received = [Signal_Received; Signal_with_noise];
        end

        Max_lag = 12;
        x1 = Signal_Received(1,:);  % microphone 1
        x2 = Signal_Received(2,:);  % microphone 2
        R_12 = xcorr(x1, x2, Max_lag, 'coeff'); 

        % The lag between microphone 1 and 2
        [~, Lag_12_index] = max(R_12); 
        Lag_12_estimate = Lag_12_index - (Max_lag + 1);   

        Real_lag = T_D(1) - T_D(2);
        error = Lag_12_estimate - Real_lag;
        errors(iter) = error;
    end

    % Calculate average error
    average_error = mean(errors);
    average_errors(snr_index) = average_error;

    % Calculate correct detection percentage
    correct_detection_percentage = sum(errors == 0) / num_iterations;
    correct_detection_percentages(snr_index) = correct_detection_percentage;
end

% Display results
disp(['Average Errors: ', num2str(average_errors')]);
disp(['Correct Detection Percentage (SNR_dB = 30): ', num2str(correct_detection_percentages(1))]);
disp(['Correct Detection Percentage (SNR_dB = 10): ', num2str(correct_detection_percentages(2))]);
disp(['Correct Detection Percentage (SNR_dB = -10): ', num2str(correct_detection_percentages(3))]);
