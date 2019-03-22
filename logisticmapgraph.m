function logisticmapgraph(a)
	b = linspace(0,1,1001);

	for k=1:1001
		x = b(k);
		for l=1:50
			x = a*x*(1-x);
		end
		c(k) = x;
	end

	plot(b,c);