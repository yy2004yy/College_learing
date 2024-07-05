clc;
% Solution 1:
fprintf('Solution 1:\n');
a_1 = sqrt(1+1i);
fprintf('(1)Primitive ='); disp(a_1);

a_2 = sqrt(-2+2i);
fprintf('(2)Primitive ='); disp(a_2);

a_3 = (sqrt(3) + (2*sqrt(3) - 3)*1i)^(1/6);
fprintf('(3)Primitive ='); disp(a_3);

%Solution 2:
fprintf('Solution 2:\n');
syms z1 z2

eq1 = z1 + 2*z2 == 1 + 1i;
eq2 = 3*z1 + 1i*z2 == 2 - 3i;

solutions = solve(eq1, eq2, z1, z2);

fprintf('z1 = '); disp(solutions.z1);
fprintf('z2 = '); disp(solutions.z2);

%Solution 3:
fprintf('Solution 3:\n');
syms n1
fprintf('(1)Primitive = '); A1 = limit(((3 + 4i)/6)^n1, n1,inf);
disp(A1);

syms n2
fprintf('(2)Primitive = '); A2 = limit((n2 + n2^2/2)^(1/n2), n2,inf);
disp(A2);

%Solution 4:
fprintf('Solution 4:\n');

syms z
F = (z^2 - 1)^2*(z^2 + 1)^2;
dif1 = diff(F);
vdf1=subs(dif1, z, 1i/2);
fprintf('dif1 = '); disp(dif1);
fprintf('vdf1 = '); disp(vdf1);


%Solution 5:
fprintf('Solution 5:\n');

syms z
F1 = (1 + tan(z))/(cos(z)^2);
intF1 = int(F1, z, 1, 1i);
fprintf('intF1 = '); disp(intF1);

F2 = (z - 1i)*exp(-z);
intF2 = int(F2, z, 0, 1i);
fprintf('intF2 = '); disp(intF2);


%Solution 6:
fprintf('Solution 6:\n');

syms z
f1 = sin(3 + z);
F = taylor(f1, z, 'Order', 10);
fprintf('(1)F(x) = '); disp(F);

syms z
f2 = exp(z)*log(1 + z);
F = taylor(f2, z, 'Order', 10);
fprintf('(2)F(x) = '); disp(F);

syms z
f3 = (2*z^5 + 5*z^3 + z^2 + 2)/(z^3 + 2*z^2 + 3*z + 1);
F = taylor(f3, z, 'Order', 10);
fprintf('(3)F(x) = '); disp(F);

%Solution 7:
fprintf('Solution 7:\n');

syms z
% B and A are the coefficients of z in the numerator and denominator, respectively
B = [1, 0, 0, 0, 1];
A = [1, 0, 2, 0, 1, 0];
[r, p] = residue(B, A);

fprintf('Residue size is :\n');disp(r); % Residue size
fprintf('Pole coordinates is :\n');disp(p); % Pole coordinates

%Solution 8:
fprintf('Solution 8:\n');

syms z
% B and A are the coefficients of z in the numerator and denominator, respectively
B = [2, 0, 1];
A = [2, 1, 4, -5];
[r, p] = residue(B, A);

fprintf('Residue size is :\n');disp(r); % Residue size
fprintf('Pole coordinates is :\n');disp(p); % Pole coordinates

for i = 1:length(p) % Determine whether the poles are within the integral range
    if abs(p(i))^2 <= 1 
        flag(i) = 1;
    else 
        flag(i) = 0; 
    end
end

integral = 2*pi*1i*(r(1)*flag(1) + r(2)*flag(2) + r(3)*flag(3));
fprintf('integral = '); disp(integral);

%Solution 9:
fprintf('Solution 9:\n');
subplot(1, 2, 1);
t = -10:0.1:10;
x = t; y = t.^2;
z1 = x + 1i.*y;
plot(z1);
title('z = t + i*t^2'); xlabel('x'); ylabel('y');

subplot(1, 2, 2);
t = -pi:0.01:pi;
x = t; y = exp(t).*sin(t);
z2 = x + 1i.*y;
plot(z2);
title('z = t + iexp(t)*sin(t)'); xlabel('x'); ylabel('y');




