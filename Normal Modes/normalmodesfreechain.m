function normalmodesfreechain(N)
	disp('Gives squares of Normal frequencies of a free chain')
	for p = 0:(N-1)
		eigenmatrix(p+1) = 2*sin(p*pi/(2*N));
	endfor

	A  = eye(N);
	A(1,1) = 1;
	A(1,2) = -1;
	A(N,N) = 1;
	A(N,N-1) = -1;
	for i = 2:N-1
		for j = 1:N
			if (j == i-1)
				A(i,j) = -1;
			elseif (j == i)
				A(i,j) = 2;
			elseif (j == i+1)
				A(i,j) = -1;
			else
				A(i,j) = 0;
			end
		end
	end
	A
	disp('Eigenvalues'),num_eigval=sqrt(transpose(eig(A)))
	disp('Guessed formula'),eigenmatrix

	plot(linspace(1,N,N),eigenmatrix,"*;guess;r","color","r",linspace(1,N,N),num_eigval,"x;numeric;r","color","b")
	legend("location","southeast")
