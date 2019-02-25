function showMotion(fName)
    M = load(fName);
    t = M(:, 1);
    xNum = M(:, 2);
    yNum = M(:, 3);
    xExact = M(:, 4);
    yExact = M(:, 5);

    plot(xNum, yNum,'xb;numerical;', xExact, yExact,'-r;exact;','linewidth',1);
    axis([min(xNum), max(xNum), min(yNum), max(yNum)]);
    xlabel ("x position");
    ylabel ("y position")
    grid on;
