function boundaryPlot(ord)
	coefs = ones(ord+1,1);
	for k=2:ord
		ind = ord + 1 -k;
		coefs(ind) = coefs(ind + 1)/k;
	end
	%The above function creates the coefficients of 
	% Taylor Series of exp(z).
	% The below function plots the values of points 
	% for which the above function has magnitude 1,
	% i.e. it is of the form exp(i*theta) for some 
	% theta.
	
	N = 501;
	angs = linspace(-pi,pi,501);
	x = zeros(N * ord,1);
	y = zeros(N * ord,1);
	for k=1:N
		coefs(ord + 1) = 1 - exp(i * angs(k));
		r = roots(coefs);
		for m=1:ord
			x(k*ord + m) = real(r(m));
			y(k*ord + m) = imag(r(m));
		end
	end

	plot(x,y,".");
	axis equal;
	grid on;
	line([0 0],[1.2*min(y) 1.2*max(y)]); %y axis
	line([2*min(x) 2*max(x)],[0 0]); %x axis
