clc;
clear;

% Define constants and parameters
adj = 17/10;  % Number
Mu_0 = 4*pi*1e-7; % Vacuum permeability, unit: H/m
a = (20 + adj)/1000;  % Outer radius of the coil, 1.5 mm
I = 1; % Current through the coil, 1 A

% Calculate theoretical magnetic induction B
r_values = linspace(-10e-3, 10e-3, 1000); 
B = Mu_0 * I * a^2 ./ (2 * (a^2 + r_values.^2).^1.5);

% Load simulation data from TXT file
data = importdata('2_z_B.txt');
data = data.data;
data(:, 1) = data(:, 1) * 1e-3; % Convert mm to m

% Extract the value at z = 0 from simulation data
z_sim_zero_idx = find(data(:, 1) == 0);
if ~isempty(z_sim_zero_idx)
    B_sim_zero = data(z_sim_zero_idx, 2);
    disp(['Actual measurement B at z = 0: ', num2str(B_sim_zero), ' T']);
else
    disp('No simulation data found for z = 0');
end




% Calculate and display the center magnetic field B
B_center = (Mu_0 * I * a^2) / (2 * a^3);
disp(['Theoretical calculation B at z = 0: ', num2str(B_center), ' T']);


% Plot the results
figure;
plot(r_values,B, 'b--', 'LineWidth', 1); % Theoretical values
hold on;
scatter(data(:, 1), data(:, 2), 30, 'r'); % Simulation values
grid on;

% Add title and labels
title('Magnetic Field B along the z-axis of a Circular Wire');
xlabel('Distance along the axis (m)');
ylabel('Magnetic Field B (T)');


% Add legend
legend('Theoretical B', 'Simulation B', 'Location', 'Best');

hold off;