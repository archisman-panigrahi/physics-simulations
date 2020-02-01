function cylplot(alpha,rmax,points)
	alpha_rad = alpha * pi/180;
	r = linspace(0,rmax,points);
	theta = linspace(0,alpha_rad,points);

	[rr,tt] = meshgrid(r,theta);

	% a = 1;
	% d = 0.5;
	% b = a * a/d;

	% z = 1 ./sqrt(rr .* rr + d * d - 2 * d * rr .* cos(tt)) - 1./sqrt(rr .* rr * d * d/(a*a)+ a * a - 2 * d * rr .* cos(tt));

	z = (2/pi) * atan2(2 * rr .* sin(tt), 1- (rr .* rr));

	mesh(rr.*cos(tt),rr.*sin(tt),z);