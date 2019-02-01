function ynext = stepRK1(h, x, y, fName, userParams)
    k = h * feval(fName, x, y, userParams);
    ynext = y + k;
