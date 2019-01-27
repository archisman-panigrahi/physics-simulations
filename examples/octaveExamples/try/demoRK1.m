function demoRK1(tf,nsteps)
	tstep = tf/nsteps;
	t = linspace(0,tf,nsteps+1);

	u = zeros(size(t));
	u(1) = 1;

	for k=1:nsteps
		u(k+1) = stepRK1_np(tstep,t(k),u(k),'fn');
	end

	utrue = exp(t);
	figure(1);
	plot(t, u, '-r;EulerForward;', t, utrue, '-g;exact;');
	figure(2);
	plot(t, utrue - u,'-r;Error;');