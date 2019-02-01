function compareRK(fName)
    M = load(fName);
    x = M(:,1);
    yRK1 = M(:,2);
    yRK2 = M(:,3);
    yRK4 = M(:,4);
    yExact = M(:,5);
    errRK1 = yExact - yRK1;
    errRK2 = yExact - yRK2;
    errRK4 = yExact - yRK4;
    figure(1);
    plot(x, yExact, '-k;Exact;', ...
         x, yRK1, '-r;Euler forward;', ...
         x, yRK2, '-g;RK2;', ...
         x, yRK4, '-b;RK4;');
    grid on;
    axis('tight');
    figure(2);
    plot(x, errRK1, '-r;Error in Euler forward;', ...
         x, errRK2, '-g;Error in RK2;', ...
         x, errRK4, '-b;Error in RK4;');
    grid on;
    axis('tight');
    figure(3);
    plot(x, errRK4, '-b;Error in RK4;');
    grid on;
    axis('tight');
