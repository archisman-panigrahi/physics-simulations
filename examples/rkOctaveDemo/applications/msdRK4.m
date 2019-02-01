function msdRK4(m, b, k, x_0, v_0, tf, nsteps)
    msdParams = [m; b; k];
    tstep = tf / nsteps;
    t = linspace(0, tf, nsteps + 1);
    omega_0 = sqrt(k/m);
    alpha = 0.5*b/m;
    if (alpha < omega_0)
        % We have an underdamped system
        omega_d = sqrt(omega_0 * omega_0 - alpha * alpha);
        rat = alpha/omega_d;
        phi = omega_d * t;
        cp = cos(phi);
        sp = sin(phi);
        decayFactor = exp(-alpha*t);
        xDisp = decayFactor .* (cp + rat*sp);
        xVel = (1.0/omega_d) * decayFactor .* sp;
        xExact = x_0 * xDisp + v_0 * xVel;
        % omega_d
        % t1 = pi/omega_d
    elseif (alpha == omega_0)
        decayFactor = exp(-angc);
        xDisp = decayFactor .* (1+angc);
        xVel = (1.0/omega_0) * decayFactor .* angc;
        xExact = x_0 * xDisp + v_0 * xVel;
    else
        alpha_r = sqrt(alpha * alpha - omega_0 * omega_0);
        s1 = -alpha + alpha_r;
        s2 = -alpha - alpha_r;
        rat = alpha/alpha_r;
        phi = alpha_r * t;
        cp = cosh(phi);
        sp = sinh(phi);
        decayFactor = exp(-alpha*t);
        xDisp = decayFactor .* (cp + rat*sp);
        xVel = (1.0/alpha_r) * decayFactor .* sp;
        xExact = x_0 * xDisp + v_0 * xVel;
    end

    xRK = zeros(size(t));
    u = [x_0; v_0];
    xRK(1) = u(1);
    for k=1:nsteps
        uNext = stepRK4(tstep, t(k), u, 'fnMSD', msdParams);
        u = uNext;
        xRK(k+1) = u(1);
    end

    figure(1);
    plot(t, xRK, '-g;RK4;', t, xExact, '-k;Exact;');
    grid on;
    figure(2);
    plot(t, xExact - xRK, '-r;Error;');
    grid on;
