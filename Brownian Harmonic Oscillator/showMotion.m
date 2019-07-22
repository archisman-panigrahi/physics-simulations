function showMotion(fName)

    M = load(fName);
    t = M(:, 1);
    position = M(:, 2);
    velocity = M(:, 3);
    Energy_x = M(:,4);
    Energy_v = M(:,5);
    % TotEnergy = Energy_x + Energy_v;
    figure 1;
    plot(t,position);
    xlabel ("time (s)");
    ylabel ("position (m)");
    grid on;
    figure 2;
    plot(t,velocity);
    xlabel ("time (s)");
    ylabel ("velocity (m/s)");
    grid on;
    figure 3;
    plot(t, Energy_x, "-r;Energy in first rotating coordinate;","linewidth", 2, t, Energy_v,"-g;Energy in second rotating coordinate;", "linewidth",2);
    xlabel ("time (s)");
    ylabel ("Energy (J)");
    grid on;