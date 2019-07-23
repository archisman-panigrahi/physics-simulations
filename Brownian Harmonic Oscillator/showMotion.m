function showMotion()

    M = csvread('output.csv');
    r = M(1,2)
    t = M(2:length(M), 1);
    position = M(2:length(M), 2);
    velocity = M(2:length(M), 3);
    Energy_x = M(2:length(M),4);
    Energy_v = M(2:length(M),5);
    delta_t = t(2) - t(1);
    Average_Energy_1st = add_all_elements(Energy_x)/(max(size(t)))
    Average_Energy_2nd = add_all_elements(Energy_v)/(max(size(t)))
    Experimental_Ratio = Average_Energy_1st/Average_Energy_2nd
    Ratio_expected_by_me = (2*cosh(2*r) + sinh(2*r))/(2*cosh(2*r) - sinh(2*r))
    Ratio_expected_in_paper = exp(2*r)
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
    % pause()

function s = add_all_elements(a)
    s = 0;
    for i=1:max(size(a))
        s = s + a(i);
    end