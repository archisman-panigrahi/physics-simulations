function showMotion()

    N = csvread('details.csv');
    r = N(1,2)
    Average_Energy_1st_rotating_coordinate = N(2,2)
    Average_Energy_2nd_rotating_coordinate = N(3,2)
    Total_Energy = N(4,2)
    Experimental_Ratio = N(5,2)
    Ratio_expected_by_me = N(6,2)
    Ratio_expected_in_paper = N(7,2)

    Average_Potential_Energy = N(8,2)
    Average_Kinetic_Energy = N(9,2)
    Ratio_of_potential_and_kinetic_energy = N(8,2)/N(9,2)


    M = csvread('output.csv');
    % r = M(1,2)
    t = M(2:length(M), 1);
    position = M(2:length(M), 2);
    velocity = M(2:length(M), 3);
    Energy_rot_1 = M(2:length(M),4);
    Energy_rot_2 = M(2:length(M),5);
    Energy_x = M(2:length(M),6);
    Energy_v = M(2:length(M),7);

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
    plot(t, Energy_rot_1, "-r;Energy in first rotating coordinate;","linewidth", 2, t, Energy_rot_2,"-g;Energy in second rotating coordinate;", "linewidth",2);
    xlabel ("time (s)");
    ylabel ("Energy (J)");
    figure 4;
    plot(t, Energy_x, "-r;Potential Energy;","linewidth", 2, t, Energy_v,"-g;Kinetic Energy;", "linewidth",2);
    xlabel ("time (s)");
    ylabel ("Energy (J)");
    grid on;
    % pause()

% function s = add_all_elements(a)
%     s = 0;
%     for i=1:max(size(a))
%         s = s + a(i);
%     end