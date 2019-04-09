function disc(rho, phi0)
	N = 401;
	phi = linspace(-pi,pi,N);
	fac = (1+rho)/(1-rho);
	ang1 = (phi0 - phi)/2;
	res1 = atan2(fac * sin(ang1),cos(ang1))/pi;
	ang2 = (-phi0 - phi)/2;
	res2 = atan2(fac * sin(ang2),cos(ang2))/pi;
	res = res1 - res2;
	plot(phi,res);
	axis('tight');