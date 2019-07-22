function showMotion(fName)

    M = load(fName);
    t = M(:, 1);
    thetaNum = M(:, 2);
    angVelNum = M(:, 3);

    figure 1;
    plot(t,thetaNum);
    xlabel ("time");
    ylabel ("theta");
    figure 2;
    plot(t, angVelNum);
    xlabel ("time");
    ylabel ("angular velocity");
    grid on;
