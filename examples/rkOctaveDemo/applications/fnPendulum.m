function s = fnPendulum(t, u, pendulumParams)
    L = pendulumParams(1);
    g = pendulumParams(2);
    s = [u(2); -(g/L)*sin(u(1))];
