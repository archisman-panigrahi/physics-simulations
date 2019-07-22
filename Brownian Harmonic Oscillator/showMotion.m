function showMotion(fName)

    M = load(fName);
    t = M(:, 1);
    position = M(:, 2);
    velocity = M(:, 3);
    Energy_x = M(:,4);
    Energy_v = M(:,5);

    figure 1;
    plot(t,position);
    xlabel ("time");
    ylabel ("theta");
    grid on;
    figure 2;
    plot(t,velocity);
    xlabel ("time");
    ylabel ("velocity");
    grid on;
    figure 3;
    plot(t,Energy_x, "-r;Energy_x;","linewidth", 2, t, Energy_v,"-g;Energy_v;", "linewidth",2);
    xlabel ("time");
    ylabel ("Energy");
    grid on;