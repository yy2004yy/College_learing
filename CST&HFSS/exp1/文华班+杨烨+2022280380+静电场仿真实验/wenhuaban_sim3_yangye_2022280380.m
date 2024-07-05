% Define constants and parameters
adj = 17/10;
epsilon_0 = 8.854187817e-12; % Vacuum permittivity, unit: F/m
a = 10/1000; % Radius of the inner sphere, unit: m
b = (20 + adj*10)/1000; % Radius of the outer sphere, unit: m
t = 4; % Relative permittivity
% rho = Q/((4/3)*pi*(a^3)); % Charge density, unit: C/m^3

% Calculate the total charge of the sphere Q = 1 C
Q = 1;

% Define the function to calculate electric field strength E
E = @(r) (1 / (4 * pi * t * epsilon_0)) * (Q / (r^2)) .* (a <= r & r <= b) + (1 / (4 * pi * epsilon_0)) * (Q / (r^2)) .* (r > b);

% Define the function to calculate electric displacement D
D = @(r) (1 / (4 * pi) * (Q / (r^2)) .* (a <= r & r <= b) + (1 / (4 * pi)) * (Q / (r^2)) .* (r > b));

% Define the range of r
r_values = linspace(0, 5*a, 1000); % Range from 0 to 5a, 1000 points

% Calculate electric field strength E and electric displacement D
E_values = arrayfun(E, r_values);
D_values = arrayfun(D, r_values);

% Create two subplots
subplot(1, 2, 1); % First subplot
plot(r_values, E_values, 'b-');
xlabel('X (m)');
ylabel('Electric Field Strength (N/C)');
title('Electric Field Strength vs. X');
legend('E(r)');
grid on;
hold on;

% Import data and plot
m = importdata('NO3_e.txt');
data = m.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('E-field Comparison'); % Modify title
hold off;

% Second subplot
subplot(1, 2, 2); % Second subplot
plot(r_values, D_values, 'b-');
xlabel('X (m)');
ylabel('Electric Displacement (C/m^2)');
title('Electric Displacement vs. X');
legend('D(r)');
grid on;

hold on;

% Import data and plot
j = importdata('NO3_d.txt');
data = j.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('Electric Displacement Comparison'); % Modify title
hold off % End plotting
