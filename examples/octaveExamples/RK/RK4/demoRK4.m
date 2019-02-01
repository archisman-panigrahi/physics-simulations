function demoRK4(m, b, k, y_0, v_0, xf, nsteps)

	
	y_0
	v_0
	m
	b
	k
	xf
	nsteps

	omega_0 = sqrt(k/m);
	damping = b/(2*m);
	omega = sqrt(omega_0 * omega_0 - damping * damping);
	
	omega_0
	omega
	damping

	delta_x = xf/nsteps;
	x = linspace(0, xf, nsteps + 1);
	userParameters = [m; b; k];
	yRK = zeros(size(x));
	u = [y_0; v_0];

	yRK(1) = u(1);

	for k=1:nsteps
		uNext = stepRK4(delta_x, x(k), u, 'fn', userParameters);
		u = uNext;
		yRK(k+1) = u(1);
	end

	expDamp = exp(-damping * x);
	% yExact = (y_0 * cos(omega * x) + (((v_0 + damping * y_0)/omega) * sin(omega * x)));

	yExact = expDamp .* (y_0 * cos(omega * x) + ((v_0 + damping * y_0)/omega) * sin(omega_0 * x));
	% I forgot to write "end" and it showed syntax error.
	% if b^2< 4(k*m)
	% 	z = 2 + 3
	% % elseif b^2 == 
	% % 	body
	% % else
	% % 	body
	% end
	figure(1);
	plot(x, yRK, '-g;RK4;', x, yExact, '-r;Exact Solution;');
	grid on;
	figure(2);
	plot(x, yExact - yRK, '-b; Error;')