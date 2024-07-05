% Define constants and parameters
adj = 17/10; % Number
Mu_0 = 4*pi*1e-7; % Vacuum permeability, unit: H/m
MU = 4 + adj; % Relative permeability of the material
a = 0.5/1000; % Inner radius of the coil, 0.5 mm
b = 1/1000; % Outer radius of the coil, 1 mm
c = 1.5/1000; % Radius of the core, 1.5 mm
I = 1; % Current through the coil, 1 A

% Define the magnetic field function B(r)
B = @(r) Mu_0*I*abs(r)/(2*pi*(a^2)).*(abs(r) < a) + Mu_0*MU*I/(2*pi*abs(r)).*(a <= abs(r) & abs(r) < b) ...
    + Mu_0*I/(2*pi*abs(r))*(1 - (r.^2 - b^2)/(c^2 - b^2)).*(b <= abs(r) & abs(r) < c);

% Define the magnetic field function H(r)
H = @(r) I*abs(r)/(2*pi*(a^2)).*(abs(r) < a) + I/(2*pi*abs(r)).*(a <= abs(r) & abs(r) < b) ...
    + I/(2*pi*abs(r))*(1 - (r.^2 - b^2)/(c^2 - b^2)).*(b <= abs(r) & abs(r) < c);

% Define the range of r
r_values = linspace(-20*a, 20*a, 1000); % Range from -20a to 20a, 1000 points

% Calculate magnetic field strength B and H
B_values = arrayfun(B, r_values);
H_values = arrayfun(H, r_values);

% Plot the variation of magnetic field strength B with distance r
figure;

plot(r_values, B_values, 'b--',  'LineWidth', 1); 
xlabel('X (m)');
ylabel('Magnetic Field Strength (T)');
title('Magnetic Field Strength B(r) vs. X');
legend('Calculated');
grid on;
axis([-6*a 6*a 0 max(B_values)]);
hold on;

% Import and plot B-field data
B_data = importdata('3_x_B.txt');
data_B = B_data.data;
scatter(data_B(:,1)/1000, data_B(:,2), 30, 'r');
legend('Calculated', 'Simulated');
title('B-field Comparison');
hold off;
figure;

% Plot the variation of magnetic field strength H with distance r

plot(r_values, H_values, 'b--',  'LineWidth', 1); 
xlabel('X (m)');
ylabel('Magnetic Field Strength (A/m)');
title('Magnetic Field Strength H(r) vs. X');
legend('Calculated');
grid on;
axis([-6*a 6*a 0 max(H_values)]);
hold on;

% Import and plot H-field data
H_data = importdata('3_x_H.txt');
data_H = H_data.data;
scatter(data_H(:,1)/1000, data_H(:,2), 30, 'r');
legend('Calculated', 'Simulated');
title('H-field Comparison');
hold off;
