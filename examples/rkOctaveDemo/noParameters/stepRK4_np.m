function ynext = stepRK4_np(h, x, y, fName)
    k1 = h * feval(fName, x, y);
    k2 = h * feval(fName, x + 0.5 * h, y + 0.5 * k1);
    k3 = h * feval(fName, x + 0.5 * h, y + 0.5 * k2);
    k4 = h * feval(fName, x + h, y + k3);
    ynext = y + (k1 + 2 * k2 + 2 * k3 + k4 ) / 6;
