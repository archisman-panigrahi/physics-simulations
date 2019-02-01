function yNext = stepRK4(h,x,y,fName,parameters)
	k1 = h * feval(fName, x , y, parameters);
	k2 = h * feval(fName, x + 0.5 * h, y + 0.5 * k1, parameters);
	k3 = h * feval(fName, x + 0.5 * h, y + 0.5 * k2, parameters);
	k4 = h * feval(fName, x + h, y + k3, parameters);

	yNext = y + (k1 + 2 * k2 + 2 * k3 + k4)/6 ;