function ynext = stepRK4(h, x, y, fName, userParams)
    k1 = h * feval(fName, x, y, userParams);
    k2 = h * feval(fName, x + 0.5 * h, y + 0.5 * k1, userParams);
    k3 = h * feval(fName, x + 0.5 * h, y + 0.5 * k2, userParams);
    k4 = h * feval(fName, x + h, y + k3, userParams);
    ynext = y + (k1 + 2 * k2 + 2 * k3 + k4 ) / 6;
