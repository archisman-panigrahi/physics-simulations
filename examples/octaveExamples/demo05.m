M = load('u.dat');
x = M(:, 1);
y = M(:, 2);
c = polyfit(x, y, 2)
xFine = linspace(min(x), max(x), 101);
yFit = polyval(c, xFine);
plot(x, y, '*', xFine, yFit);
grid on;
