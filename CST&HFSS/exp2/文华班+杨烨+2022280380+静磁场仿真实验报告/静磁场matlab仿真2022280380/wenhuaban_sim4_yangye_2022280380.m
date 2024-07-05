% Define constants and parameters
adj = 17/10;
Mu_0 = 4*pi*1e-7; % Vacuum permeability, unit: H/m
a = 1/1000; % Radius of the coil, 1 mm
d = 1/1000; % Distance between the centers of the cylinders, m
I = 1; % Current through the coil, 1 A

% Calculate the current density
overlap_area = 2 * (1/3 * pi * 1e-6 - 1/4 * sqrt(3) * 1e-6);
J = I / (pi * a^2 - overlap_area);

% Range of x-axis values (meters)
x_values = linspace(-0.4e-3, 0.4e-3, 1000); 
% Initialize array for magnetic induction intensity B
B_values = zeros(size(x_values));

% Calculate magnetic induction intensity B along the x-axis
for i = 1:length(x_values)
    % Superpose magnetic induction intensities (considering magnitude only)
    B_values(i) = Mu_0*J*d /2;
end

% Import data and plot
try
    data = importdata('4_x_B.txt');
    if isstruct(data)
        data = data.data;
    end
    r_sim_B = data(:, 1) * 1e-3; % Convert r values from mm to meters
    B_sim = data(:, 2);
catch
    warning('Data file not found or error in importing data.');
    r_sim_B = [];
    B_sim = [];
end


disp(['Actual measurement of B between 0.4mm and 0.4mm : ', num2str(B_values(i)), ' T']);
disp(['Theoretical calculation of B between 0.4mm and 0.4mm : ', num2str(B_sim(length(B_sim)/2)), ' T']);

% Plot the variation of magnetic field strength B with distance r
figure;
plot(x_values, B_values, 'b-', 'LineWidth', 2); 
xlabel('X (m)');
ylabel('Magnetic Field Strength (T)');
title('Magnetic Field Strength vs. X');
legend('Calculated');
grid on;
hold on;
if ~isempty(r_sim_B) && ~isempty(B_sim)
    scatter(r_sim_B, B_sim, 10, 'r'); % Simulation results
    legend('Calculated', 'Simulated'); % Modify legend labels
end
hold off; % End plotting
