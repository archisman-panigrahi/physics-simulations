function s = fnMSD(t, u, msdParams)
    m = msdParams(1);
    b = msdParams(2);
    k = msdParams(3);
    s = [u(2); -((k/m)*u(1)+(b/m)*u(2))];
