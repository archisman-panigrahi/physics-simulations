function surfdisc(phi0, nRho, nPhi)
	rhoLin = linspace(0,1,nRho+1);
	phiLin = linspace(-pi,pi,nPhi+1);
	[rho,phi] = meshgrid(rhoLin, phiLin);
	u = zeros(size(rho));

	for k=1:nRho
		u(:,k) = uofPhi(rhoLin(k),phi0,phi(:,k));
	end
	u(:,nRho+1) = abs(phiLin(k)) < phi0;

	x = cos(phi) .* rho;
	y = sin(phi) .* rho;
	surf(x,y,u);
	axis on;
	colorbar;

function res = uofPhi(rho,phi0,phi)
	fac = (1+rho)/(1-rho);
	ang1 = (phi0 - phi)/2;
	res1 = atan2(fac * sin(ang1),cos(ang1))/pi;
	ang2 = (-phi0 - phi)/2;
	res2 = atan2(fac * sin(ang2),cos(ang2))/pi;
	res = res1 - res2;