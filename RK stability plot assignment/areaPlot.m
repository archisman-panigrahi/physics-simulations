function areaPlot(xmin,xmax,ymin,ymax,M,N,ord)
	x=linspace(xmin,xmax,M);
	y=linspace(ymin,ymax,N);

	coefs = ones(ord + 1, 1);
		for k = 2:ord
			ind = ord + 1 - k;
			coefs(ind) = coefs(ind + 1)/k;
		end

	img = ones(M,N);
	for ix=1:M
		for iy=1:N
			z = x(ix) + i*y(iy);
			v = polyval(coefs,z);
			mag = abs(v);
			img(N + 1 - iy, ix) = 1 + mag;
		end
	end

	colormap([0 0 0;0 1 0]);
	image([xmin,xmax],[ymin,ymax],img);
	axis('equal');
	grid on;