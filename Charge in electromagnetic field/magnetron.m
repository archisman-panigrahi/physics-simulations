function magnetron(fName,a,b)

    M = load(fName);
    t = M(:, 1);
    xNum = M(:, 2);
    yNum = M(:, 3);

    t_a = linspace(0,2.*pi,101);

    plot(a.*cos(t_a),a.*sin(t_a), "-g","linewidth", 5, b.*cos(t_a),b.*sin(t_a), "-r","linewidth", 5, xNum, yNum,'-b;numerical solution;', 'linewidth',2);

    axis([-1.2 * b, 1.2 * b, -1.2 * b, 1.2 * b]);
    xlabel ("x position");
    ylabel ("y position");
    grid on;
