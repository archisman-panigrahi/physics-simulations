function s = fn(t, u, parameters)
	m = parameters(1);
	b = parameters(2);
	k = parameters(3);

	s = [u(2); -((k/m) * u(1) + (b/m) * u(2))];
	%Simple Harmonic oscillator