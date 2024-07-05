% Define constants and parameters
adj = 17/10;
epsilon_0 = 8.854187817e-12; % Vacuum permittivity, unit: F/m
epsilon_r = 1 + adj;  % Relative permittivity, unit: F/m
Q = 1; % Charge, unit: C
a = 10/1000; % Radius of the sphere, unit: m
rho = Q/((4/3)*pi*(a^3)); % Charge density, unit: C/m^3

% Define the function to calculate electric field strength E
E = @(r) (rho/(3*epsilon_0*epsilon_r)) * r .* (r <= a) + (rho*(a^3))/(3*epsilon_0*(r^2)).* (r > a);

% Define the range of r
r_values = linspace(0, 4*a, 1000); % Range from 0 to 5a, 1000 points

% Calculate electric field strength E
E_values = arrayfun(E, r_values);

% Plot the variation of electric field strength E with distance r
plot(r_values, E_values, 'b-'); 
xlabel('X(m)');
ylabel('Electric Field Strength (N/C)');
title('Electric Field Strength vs. X');
legend('E(r)');
grid on;
axis([0 4*a 0 max(E_values)]); % Set the range of the coordinate axis
hold on 

% Import data and plot
a = importdata('NO1_e.txt');
data = a.data;
plot(data(:,1)/1000, data(:,2), 'r--'); % Plot imported data with red line
legend('Calculated', 'Simulated'); % Modify legend labels
title('E-field Comparison'); % Modify title
hold off % End plotting
