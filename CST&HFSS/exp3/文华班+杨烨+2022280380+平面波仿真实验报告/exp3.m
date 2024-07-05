% Constants
f = 2.4e9; % Frequency in Hz
c = 3e8; % Speed of light in vacuum in m/s
lambda = c / f; % Wavelength in meters
omega = 2 * pi * f; % Angular frequency
k = 2 * pi / lambda; % Wave number
E0 = 1; % Electric field amplitude in V/m
phi = 0; % Initial phase

% Time at t = T/4
T = 1 / f; % Period
t = T/4; % Time at t = T/4

% Z-axis range from 0mm to 40mm
z = linspace(0, 40e-3, 1000); % 1000 points from 0 to 40mm

% Relative permittivities (from the problem statement)
eta0 = 120*pi;
adj = 1.7; % Adjusted value based on problem definition
epsilon1 = 2 + adj;
epsilon2 = 3 + adj;
epsilon3 = 4 + adj;

eta1 = eta0 / sqrt(epsilon1);
eta2 = eta0/ sqrt(epsilon2);
eta3 = eta0/ sqrt(epsilon3);

beta1=omega*sqrt(epsilon1)/c;
beta2=omega*sqrt(epsilon2)/c;
beta3=omega*sqrt(epsilon3)/c;

dz1=10*1e-3;
dz2=20*1e-3;
dz3=30*1e-3;

%First-order equivalence
eta_eq1=eta3*(eta0+1j*eta3*tan(beta3*dz3))/(eta3+1j*eta0*tan(beta3*dz3));
eta_eq2=eta2*(eta_eq1+1j*eta2*tan(beta2*dz2))/(eta2+1j*eta_eq1*tan(beta2*dz2));
eta_eq3=eta1*(eta_eq2+1j*eta3*tan(beta1*dz1))/(eta1+1j*eta_eq2*tan(beta1*dz1));


% Initialize fields
E_total = zeros(size(z));
E_incident = E0 *exp(-1j*k*z)*exp(1i * omega * t);



% Calculate reflected field and add to total field
gamma1 = (eta_eq3 - eta0) / (eta_eq3 + eta0);
E_refl_region = gamma1* E_incident;
E_total = E_total + E_incident + E_refl_region;

% Plotting the results
figure;
a=importdata("data\total.csv");
data1=a.data;
plot(z * 1e3, real(E_total),data1(1:18,3),data1(1:18,4));
legend('cal','sim');
xlabel('z (mm)');
ylabel('Electric Field Intensity (V/m)');
title('Total  Electric Fields along z-axis between 0mm and 40mm');
grid on;

figure;
b=importdata("data\scatter.csv");
data2=b.data;
plot(z * 1e3, abs(real(E_refl_region)),data2(1:18,3),data2(1:18,4));
legend('cal','sim');
hold off;

xlabel('z (mm)');
ylabel('Electric Field Intensity (V/m)');
title(' Scattered Electric Fields along z-axis between 0mm and 40mm');
legend;
grid on;
