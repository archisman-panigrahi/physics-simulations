function ynext = stepRK2_np(h, x, y, fName)
    c2 = 2.0 / 3.0;
    b1 = 0.25;
    b2 = 0.75;
    k1 = h * feval(fName, x, y);
    k2 = h * feval(fName, x + c2 * h, y + c2 * k1);
    ynext = y + b1 * k1 + b2 * k2;
