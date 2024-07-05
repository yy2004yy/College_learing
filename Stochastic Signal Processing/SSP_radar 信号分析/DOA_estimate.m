clc
clear 

num_micro = 8;   % Number of microphones
c = 340;         % Speed of sound in air is 340m/s
d_01 = 0.085;       % Spacing
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
    Loc(2,i) = d_01*i;
end
Loc_M_y = Loc(2,:);

% Calculate different directions of arrival (DOA) produced by different lags
num = 100;  % Number of DOAs (-pi/2 to pi/2)
theta = linspace(-pi/2, pi/2, num);  % DOAs from -pi/2 to pi/2

% Randomly select a theta for each iteration
random_index = randi(numel(theta));
random_theta = theta(random_index);
random_theta*(180/pi)

sin_r_theat = sin(random_theta);

d = Loc_M_y;
t_d = d*sin_r_theat/c;
real_lag = t_d*N;
real_lag = round(real_lag);
T_D = 88 + real_lag; % Calculate the time delay corresponding to the selected DOA

% Calculate SNR
SNR_dB = 30;
signal_power = sig_ori*sig_ori'/Len_sig;       % calculate signal power
noise_power = signal_power/(10^(SNR_dB/10));   % noise

Signal_Received = [];
for p = 1:num_micro
    noise = sqrt(noise_power)*randn(1, Len_sig); 
    sig_noise = sig_ori + noise;
    Signal_with_noise=[sqrt(noise_power)*randn(1, T_D(p)), sig_noise, sqrt(noise_power)*randn(1, max(T_D)-T_D(p))]; 
    Signal_Received = [Signal_Received; Signal_with_noise];
end

Max_lag = 89;  % Set the maximum lag value

errors_iter = zeros(1, num_micro - 1);  % Array to store the error between each pair of microphones

for mic = 2:num_micro
    % Calculate the lag estimate between the current microphone and the first microphone
    x1 = Signal_Received(1,:);
    xi = Signal_Received(mic,:);
    R_i1 = xcorr(x1, xi, Max_lag, 'coeff'); 

    % Calculate the maximum correlation value and its index
    [Lag_i1_value, Lag_i1_index] = max(R_i1); 
    Lag_i1_estimate = Lag_i1_index - (Max_lag + 1);

    % Calculate the actual lag
    Real_lag = T_D(1) - T_D(mic);

    % Calculate the error and store it in the array
    errors_iter(mic-1) = Lag_i1_estimate - Real_lag;
    
end

% Estimates for θ
estimate_theta = -asin(c*(Lag_i1_estimate)/(N*d_01*7))*(180/pi);
estimate_theta

% Angular error in arrival direction
error_of_DOA = random_theta*(180/pi) - estimate_theta;
error_of_DOA

% Output the average error between microphone 1 and each other microphone
for mic = 2:num_micro
    disp(['Average error between microphone 1 and ', num2str(mic), ': ', num2str(errors_iter(mic-1))]);
end
