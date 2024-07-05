% Define constants and parameters
epsilon_0 = 8.854187817e-12; % Vacuum permittivity, unit: F/m
k = 1 / (4 * pi * epsilon_0); % Coulomb's constant
Q = 1; % Charge, unit: C
r1 = 20/1000; % Radius of the first sphere, unit: m
r2 = 8/1000; % Radius of the second sphere, unit: m
rho = Q / ((4/3)*pi*(r1^3) - (4/3)*pi*(r2^3)); % Charge density, unit: C/m^3
c = 0.01; % Distance between the centers of the spheres, unit: m

% Range of positions along the x-axis
x_values = linspace(c - r2, c + r2, 1000); % From 2mm to 18mm

% Define the anonymous function to calculate electric field strength E
E = @(x) (rho*c)/(3*epsilon_0) .* (c - r2 <= x & x <= c + r2) ;

% Calculate electric field strength E
E_values = arrayfun(E, x_values);

% Plot electric field strength E as a function of x
figure;
plot(x_values, E_values, 'b-');
xlabel('X (m)');
ylabel('Electric Field Strength (V/m)');
title('Electric Field Strength');
legend('E-field Magnitude');
grid on;
xlim([0.002 0.018]); % Set the range of the x-axis from 2mm to 18mm

% Set the y-axis range correctly
ylim('auto'); % Automatically adjust the y-axis range

hold on;

% Import data and plot
m = importdata('NO5_e.txt');
data = m.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with a red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('E-field Comparison'); % Modify title
hold off;
