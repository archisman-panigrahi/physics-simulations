function showPendulumMotion(fName)
    M = load(fName);
    t = M(:, 1);
    theta = M(:, 2);
    theta_sa = M(:, 3);
    plot(t, theta,'-r;exact;', t, theta_sa,'-g;small angle;');
    axis([min(t), max(t), min(theta), max(theta)]);
    grid on;
