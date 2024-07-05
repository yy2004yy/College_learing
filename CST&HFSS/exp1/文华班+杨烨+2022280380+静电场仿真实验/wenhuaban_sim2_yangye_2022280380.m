% Define constants and parameters
adj = 17/10;
epsilon_0 = 8.854187817e-12; % Vacuum permittivity, unit: F/m
Q = 1 + adj; % Q = 2.7C
a = 10/1000; % Radius of the sphere, unit: mm
rho = Q/(pi*(a^2)); % Charge density, unit: C/m^3

% Define the function to calculate electric field strength E
E = @(h) (rho/(2*epsilon_0)) * (1 - h/sqrt(h^2 + a^2));

% Define the range of h
h_values = linspace(0, 5*a, 1000); % Range from 0 to 5a, 1000 points

% Calculate electric field strength E
E_values = arrayfun(E, h_values);

% Plot the variation of electric field strength E with distance Z
plot(h_values, E_values, 'b-');
xlabel('Z (m)');
ylabel('Electric Field Strength (N/C)');
title('Electric Field Strength vs. Z');
legend('E(h)');
grid on;
axis([0 3*a 0 max(E_values)]); % Set the range of the coordinate axis
hold on;

% Import data and plot
a = importdata('NO2_e.txt');
data = a.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('E-field Comparison'); 
hold off % End plotting
