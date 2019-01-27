x = linspace(-.5,2,16);
y = linspace(-2,3,16);
hold on;
h = x(2) - x(1);
k = y(2) - y(1);
for xidx = 1:16;
	tx = x(xidx);
	for yidx = 1:16;
		ty = y(yidx);
		s = -ty + tx*tx -1;
		phiAng = atan(s);
		hx = 0.3 * h * cos(phiAng);
		hy = 0.3 * h * sin(phiAng);
		plot([tx-hx,tx+hx],[ty-hy,ty+hy],'linewidth',2,'color','b');

	end
end
%z = linspace(-.5,2,101);
plot(x,(x.*x-2*x+1)+exp(-x.));
plot([0,0],[-2,3],'m');
plot([-.5,2],[0,0],'m');
axis([-.5,2,-2,3]);
grid on;
hold off;