function showPendulumMotion(fName)
    M = load(fName);
    t = M(:, 1);
    theta = M(:, 2);
    theta_sa = M(:, 3);
    plot(t, theta, 'lineWidth', 2, t, theta_sa);
    axis([min(t), max(t), min(theta), max(theta)]);
    grid on;
