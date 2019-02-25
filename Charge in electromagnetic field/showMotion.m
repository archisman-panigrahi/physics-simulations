function showMotion(fName)
    M = load(fName);
    t = M(:, 1);
    xNum = M(:, 2);
    yNum = M(:, 3);
    xExact = M(:, 4);
    yExact = M(:, 5);

    % plot(xNum, yNum,'+k;numerical;', xExact, yExact,'-r;exact;','linewidth',0.5);
    plot(xNum, yNum,'*k;numerical;');
    axis([min(xNum), max(xNum), min(yNum), max(yNum)]);
    grid on;
