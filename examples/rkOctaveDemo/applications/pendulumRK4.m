function pendulumRK4(L, g, theta_0)
    pendulumParams = [L; g];
    T_0 = 2 * pi * sqrt(L/g);
    nsteps = 2000;
    tf = 2 * T_0;
    tstep = tf / nsteps;
    t = linspace(0, tf, nsteps + 1);
    theta_small_ang_approx = theta_0 * cos(2*pi*t/T_0);
    theta_RK = zeros(nsteps + 1, 1);

    u = [theta_0; 0];
    theta_RK(1) = theta_0;
    for k=1:nsteps
        uNext = stepRK4(tstep, t(k), u, 'fnPendulum', pendulumParams);
        u = uNext;
        theta_RK(k+1) = u(1);
    end

    plot(t, theta_RK, 'lineWidth', 2, t, theta_small_ang_approx);
    axis([0, tf, -theta_0, theta_0]);
    grid on;
    xlabel('t');
    ylabel('\theta');
