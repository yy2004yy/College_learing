% Define constants and parameters
epsilon_0 = 8.854187817e-12; % Vacuum permittivity, unit: F/m
adj = 1.7; % Increase in relative permittivity of the upper part
inner_radius = 10/1000; % Inner conductor radius, unit: m
outer_inner_radius = 20/1000; % Outer conductor inner radius, unit: m
q = 1; % Charge on the conductor, unit: C

% Relative permittivity
epsilon_r_upper = 2 + adj;
epsilon_r_lower = 4;

% Define the function to calculate electric field strength E
E = @(r) (q / (2 * pi * (epsilon_r_upper*epsilon_0 + epsilon_r_lower*epsilon_0) * r^2)) .* (inner_radius <= r & r <= outer_inner_radius) ... 
    + (q / (2 * pi * (epsilon_r_upper*epsilon_0 + epsilon_r_lower*epsilon_0) * r^2)) .* (-inner_radius >= r & r >= -outer_inner_radius);

% Define the function to calculate D
D = @(r) ((epsilon_r_upper*epsilon_0*q) / (2 * pi * (epsilon_r_upper*epsilon_0 + epsilon_r_lower*epsilon_0) * r^2)) .* (inner_radius <= r & r <= outer_inner_radius) ... 
    + ((epsilon_r_lower*epsilon_0*q) / (2 * pi * (epsilon_r_upper*epsilon_0 + epsilon_r_lower*epsilon_0) * r^2)) .* (-inner_radius >= r & r >= -outer_inner_radius);

% Since it's a concentric spherical capacitor, we only consider the range from r = inner_radius to r = 2 * outer_inner_radius
r_values = linspace(-2 * outer_inner_radius, 2 * outer_inner_radius, 1000); % Update the range of r

% Calculate electric field strength E and the combined electric displacement D_combined
E_values = arrayfun(E, r_values);
D_values = arrayfun(D, r_values);

% Plot electric field strength E and electric displacement D as a function of distance r
figure;
subplot(1, 2, 1);
plot(r_values, E_values, 'b-');
xlabel('X (m)');
ylabel('Electric Field Strength (N/C)');
title('Electric Field Strength vs. X');
legend('E(r)');
grid on;
hold on;

% Import data and plot
m = importdata('NO4_e.txt');
data = m.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('E-field Comparison'); % Modify title
hold off;

subplot(1, 2, 2);
plot(r_values, D_values, 'b-');
xlabel('X (m)');
ylabel('Electric Displacement (C/m^2)');
title('Electric Displacement vs. X');
legend('D(r)');
grid on;

hold on;

% Import data and plot
j = importdata('NO4_d.txt');
data = j.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('Electric Displacement Comparison'); % Modify title
hold off % End plotting
