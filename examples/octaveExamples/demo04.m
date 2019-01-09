
phi = linspace(0, pi, 1001);
r = sin(5 * phi);
x = r .* cos(phi);
y = r .* sin(phi);
figure(1);
plot(x, y);
grid on;
figure(2);
plot(x, y);
axis equal;
axis off;
