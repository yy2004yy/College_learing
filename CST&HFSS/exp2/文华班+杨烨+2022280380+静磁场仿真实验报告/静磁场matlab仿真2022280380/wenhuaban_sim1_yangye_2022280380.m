% Define constants and parameters
adj = 17/10;  % Serial number
Mu_0 = 4*pi*1e-7;  % Vacuum permeability, unit: H/m
a = 1/1000;  % Inner radius of the coil, 1 mm
b = 1.5/1000;  % Outer radius of the coil, 1.5 mm
I = 2.7;  % Current through the coil, 1 A

% Define the magnetic field function B(r)
B = @(r) Mu_0*I*(r.^2 - a^2)./(2*pi*abs(r).*(b^2 - a^2)).*(abs(r) >= a & abs(r) <= b) + Mu_0*I./(2*pi*abs(r)).*(abs(r) > b);

% Define the range of r
r_values = linspace(-10*a, 10*a, 1000); % Range from -10a to 10a, 1000 points

% Calculate magnetic field strength B
B_values = arrayfun(B, r_values);

% Plot the variation of magnetic field strength B with distance r
figure;
plot(r_values, B_values, 'b--', 'LineWidth', 1); 
xlabel('X (m)');
ylabel('Magnetic Field Strength (T)');
title('Magnetic Field Strength vs. X');
legend('B(r)');
grid on;
axis([-8*a 8*a 0 max(B_values)]); % Set the range of the coordinate axis
hold on 

% Import data and plot
a = importdata('1_B.txt');
data = a.data;
scatter(data(:,1)/1000, data(:,2), 20, 'r'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('B-field Comparison'); % Modify title
hold off % End plotting