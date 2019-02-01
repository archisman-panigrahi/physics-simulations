function ynext = stepRK1_np(h, x, y, fName)
    k = h * feval(fName, x, y);
    ynext = y + k;
