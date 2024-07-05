clc
clear 
load noise.mat      % load the special noise if needed
warning off

fig = 0;                      % Figure ID
% Read the original audio file
[sig_ori, FS] = audioread('test_audio.wav');
sig_ori = sig_ori'; % Transpose the signal matrix to make it a row vector
Len_sig = length(sig_ori); % Get the length of the signal
dt = 1/FS; % Sampling interval
t = 0:dt:Len_sig/FS; % Create a time vector
t = t(1:Len_sig); % Adjust the time vector to match the signal length

SNR_dBs = [30, 10, -10]; % Different signal-to-noise ratios
for SNR_dB = SNR_dBs
    Is_add_special_noise = 0;   % if 0, add random noise; otherwise, add predefined noise
    
    % FFT 分析
    f=linspace(0,FS/2,Len_sig/2);
    f=f';
    Y=fft(sig_ori,Len_sig);
    inputy=Y(1:Len_sig/2);
    yabs=abs(Y); 
    yy=yabs(1:Len_sig/2);
    
    % 绘制 FFT 图形
    fig=fig+1;
    figure(fig)
    plot(f,yy);
    title('FFT')
    
    % this code place the microphones and source 
    M = 4;       % 4 microphones
    c = 340;     % The air is 340m/s
    Loc(1,:) = [0, 20, 0, 20]; 
    Loc_M_x = Loc(1,:);
    Loc(2,:) = [0, 0, 10, 10];
    Loc_M_y = Loc(2,:);
    
    % Signal source
    xs = 1;
    ys = 1;
    
    % calculate the distance between microphones and source 
    Rsm = [];
    for q = 1:M
         rsm = sqrt((xs-Loc_M_x(q))^2+(ys-Loc_M_y(q))^2);
         Rsm = [Rsm rsm];  % distance between microphones and source
    end
    
    % Time delay
    TD = Rsm/c; 
    L_TD = TD/dt;
    L_TD = fix(L_TD); 
    
    % Initialization of the received signal and noise addition
    Signal_Received=[];
    signal_power = sig_ori*sig_ori'/Len_sig;       % calculate signal power
    noise_power = signal_power/(10^(SNR_dB/10));   % noise
    
    % Generate analog delay for four microphones to receive signals
    for p = 1:M    
        % adding noise
        noise = sqrt(noise_power)*randn(1, Len_sig);    % assume noize is zero, or says, no noise
        if Is_add_special_noise==0
            sig_noise = sig_ori + noise;
        else
            sig_noise = sig_ori + sqrt(noise_power)*noise_default(p, 1:Len_sig);
        end   
        % adding noise finished
        
        Signal_with_noise=[sqrt(noise_power)*randn(1, L_TD(p)), sig_noise, sqrt(noise_power)*randn(1, max(L_TD)-L_TD(p))]; % add the time delay with noise 
        Signal_Received = [Signal_Received; Signal_with_noise];
    end
    % the final output Signal_Received is of size Microphone_No*Signal_Length
    
    Signal_Re_Sum = sum(Signal_Received,1);       % directly sum the signal from the M microphones
    Signal_Re_1 = Signal_Received(1,:);                 % the signal received in the first microphone
    Signal_Received_size = size(Signal_Received);
    plot_time=0:dt:(Signal_Received_size(2)-1)/FS;
    
    % plot and output the signal received in microphone 1
    fig=fig+1;
    figure(fig)
    plot(plot_time,Signal_Re_1)
    title('Signal-First')
    Signal_Re_1=Signal_Re_1./max(Signal_Re_1);
    audiowrite('Signal-First.wav',Signal_Re_1,FS);
    
    % plot and output the Sum of the signal received from all microphones directly
    fig=fig+1;
    figure(fig)
    plot(plot_time,Signal_Re_Sum)
    title('Signal-Direct-Sum')
    Signal_Re_Sum=Signal_Re_Sum./max(Signal_Re_Sum);
    audiowrite('Signal-Direct-Sum.wav',Signal_Re_Sum,FS);
    
    % plot all the received signal in one figure
    fig=fig+1;
    figure(fig)
    plot(plot_time, Signal_Received','DisplayName','Signal_Received')
    title('All Signal')
    
    % now we use xcorr, the cross-correlation, to detect the difference between
    % the microphones, and thus can add the signal correctly. 
    % Here we only show an example: add the signals from the first two microphones 
    x1 = Signal_Received(1,:);  % microphone 1
    x2 = Signal_Received(2,:);  % microphone 2
    x3 = Signal_Received(3,:);  % microphone 3
    x4 = Signal_Received(4,:);  % microphone 4
    
    Max_lag = 8000; 	               % we assume that the maximum distance between any two microphones is less than 170m, which is 0.5s, which is 8000 samples
    % note that in this case, the 0 lag, which is, the lag corresponding to 0
    % time difference, is Max_lag+1 = 8001
    R_12 = xcorr(x1, x2, Max_lag, 'coeff'); 
    R_13 = xcorr(x1, x3, Max_lag, 'coeff'); 
    R_14 = xcorr(x1, x4, Max_lag, 'coeff'); 
    
    % plot the Cross-Correlation
    lag_list = -Max_lag:Max_lag;
    fig=fig+1;
    figure(fig)
    subplot(3,1,1)
    plot(lag_list, R_12) 
    title('the Cross-Correlation')
    
    subplot(3,1,2)
    plot(lag_list, R_13) 
    title('the Cross-Correlation')
    
    subplot(3,1,3)
    plot(lag_list, R_14) 
    title('the Cross-Correlation')
    
    % the lag between microphone 1 and 2
    [Lag_12_value, Lag_12_index] = max(R_12); 
    Lag_12_estimate = Lag_12_index-(Max_lag+1);     
    
    % just to see the real lag, cannot use Real_lag = L_TD(1)-L_TD(2) in your
    % code when add the signal from different microphones
    Real_lag = L_TD(1)-L_TD(2);
    error12 = Lag_12_estimate - Real_lag;
    error12
    
    % the lag between microphone 1 and 3
    [Lag_13_value, Lag_13_index] = max(R_13); 
    Lag_13_estimate = Lag_13_index-(Max_lag+1);     
    
    % just to see the real lag, cannot use Real_lag = L_TD(1)-L_TD(3) in your
    % code when add the signal from different microphones
    Real_lag = L_TD(1)-L_TD(3);
    error13 = Lag_13_estimate - Real_lag;
    error13

    % the lag between microphone 1 and 4
    [Lag_14_value, Lag_14_index] = max(R_14); 
    Lag_14_estimate = Lag_14_index-(Max_lag+1);     
    
    % just to see the real lag, cannot use Real_lag = L_TD(1)-L_TD(4) in your
    % code when add the signal from different microphones
    Real_lag = L_TD(1)-L_TD(4);
    error14 = Lag_14_estimate - Real_lag;
    error14
    
    % Calculated maximum delay
    max_lag = max([abs(Lag_12_estimate), abs(Lag_13_estimate), abs(Lag_14_estimate)]);

    % pad zeros for four signals
    x1_pad_zero = [zeros(1, max_lag), x1, zeros(1, max_lag)];
    x2_pad_zero = [zeros(1, max_lag), x2, zeros(1, max_lag)];
    x3_pad_zero = [zeros(1, max_lag), x3, zeros(1, max_lag)];
    x4_pad_zero = [zeros(1, max_lag), x3, zeros(1, max_lag)];
   
    % Its own delay is 0
    Lag_11_estimate = 0;
    
    % Align the two signals with correct lag
    x1_with_lag = x1_pad_zero(max(0, Lag_11_estimate)+1:end-max(0, max_lag + Lag_11_estimate));    
    x2_with_lag = x2_pad_zero(max(0, -Lag_12_estimate)+1:end-max(0, max_lag + Lag_12_estimate));
    x3_with_lag = x3_pad_zero(max(0, -Lag_13_estimate)+1:end-max(0, max_lag + Lag_13_estimate));
    x4_with_lag = x4_pad_zero(max(0, -Lag_14_estimate)+1:end-max(0, max_lag + Lag_14_estimate));
    
    % Correct signal summation
    Correct_Sum_with_lag =  x1_with_lag + x2_with_lag + x3_with_lag + x4_with_lag;
    
    plot_time2=0:dt:(length(x1_with_lag)-1)/FS;

    % plot and output the Sum of the signal received from microphones 1 till 4 with correct lag
    fig=fig+1;
    figure(fig)
    plot(plot_time2,Correct_Sum_with_lag)
    title('Signal-Correct-Sum')
    Correct_Sum_with_lag=Correct_Sum_with_lag./max(Correct_Sum_with_lag);
    audiowrite('Signal-Correct-Sum.wav',Correct_Sum_with_lag,FS);
end

