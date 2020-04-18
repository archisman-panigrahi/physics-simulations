% define before calling
if ~exist('m','var')
	m = 8;
end
if ~exist('n','var')
	n = 8;
end
if ~exist('p','var')
	p = 8;
end
if ~exist('t_x','var')
	t_x = 0.1;
end

%Show the values
m,n,p,t_x
% A point is represented by coordinates (i,k,l)
% In 2D, (i,k) is mapped to (k-1)*m + i, where k varies from 1 to n, and i from 1 to m
% In 3D, (i,k,l) is mapped to (l-1)*m*n + (k-1) * m + i, where l varies from 1 to p, k from 1 to n, i from 1 to m

%The symbol j is reserved for sqrt(-1)

%Initialize
CX1Dp = zeros(m,m); %1D periodic Cosine matrix 
CX1Dnp = zeros(m,m);
SX1Dp = zeros(m,m);
SX1Dnp = zeros(m,m);

CX2Dp = zeros(m * n,m * n);
CX2Dnp = zeros(m * n,m * n);
SX2Dp = zeros(m * n,m * n); %2D non-periodic Sine matrix describing hopping in x direction
SX2Dnp = zeros(m * n,m * n);

CX2Dp = zeros(m * n,m * n);
CX2Dnp = zeros(m * n,m * n);
SX2Dp = zeros(m * n,m * n);
SX2Dnp = zeros(m * n,m * n);

CY2Dp = zeros(m * n,m * n);
CY2Dnp = zeros(m * n,m * n);
SY2Dp = zeros(m * n,m * n);
SY2Dnp = zeros(m * n,m * n); 

CX3Dp = zeros(m * n * p,m * n * p); %3D periodic Cosine matrix describing hopping in x direction
CX3Dnp = zeros(m * n * p,m * n * p);
SX3Dp = zeros(m * n * p,m * n * p);
SX3Dnp = zeros(m * n * p,m * n * p); %3D non-periodic Sine matrix describing hopping in x direction

CY3Dp = zeros(m * n * p,m * n * p);
CY3Dnp = zeros(m * n * p,m * n * p);
SY3Dp = zeros(m * n * p,m * n * p);
SY3Dnp = zeros(m * n * p,m * n * p);

CZ3Dp = zeros(m * n * p,m * n * p);
CZ3Dnp = zeros(m * n * p,m * n * p);
SZ3Dp = zeros(m * n * p,m * n * p);
SZ3Dnp = zeros(m * n * p,m * n * p);

%Constant Matrices
Const1D = eye(m);
Const2D = eye(m*n);
Const3D = eye(m*n*p);

%1D matrices
for i = 1:m-1
	CX1Dp(i+1 , i) = 1/2;
	CX1Dp(i, i+1) = 1/2;

	SX1Dp(i+1, i) = j/2;
	SX1Dp(i, i+1) = -j/2;

	CX1Dnp(i+1 , i) = 1/2;
	CX1Dnp(i, i+1) = 1/2;

	SX1Dnp(i+1, i) = j/2;
	SX1Dnp(i, i+1) = -j/2;
endfor

% For periodic systems
	CX1Dp(1 , m) = 1/2;
	CX1Dp(m, 1) = 1/2;

	SX1Dp(1, m) = j/2;
	SX1Dp(m, 1) = -j/2;

% 2D matrices

%2Dx
for k = 1:n
	for i = 1:m-1
		CX2Dp((k-1)*m + i + 1, (k-1)*m + i) = 1/2;
		CX2Dp((k-1)*m + i, (k-1)*m + i + 1) = 1/2;

		SX2Dp((k-1)*m + i + 1, (k-1)*m + i) = j/2;
		SX2Dp((k-1)*m + i, (k-1)*m + i + 1) = -j/2;

		CX2Dnp((k-1)*m + i + 1, (k-1)*m + i) = 1/2;
		CX2Dnp((k-1)*m + i, (k-1)*m + i + 1) = 1/2;

		SX2Dnp((k-1)*m + i + 1, (k-1)*m + i) = j/2;
		SX2Dnp((k-1)*m + i, (k-1)*m + i + 1) = -j/2;
	endfor
% For periodic systems
	CX2Dp((k-1)*m + 1, (k-1)*m + m) = 1/2;
	CX2Dp((k-1)*m + m, (k-1)*m + 1) = 1/2;

	SX2Dp((k-1)*m + 1, (k-1)*m + m) = j/2;
	SX2Dp((k-1)*m + m, (k-1)*m + 1) = -j/2;
endfor

%2Dy
for i = 1:m
	for k = 1:n-1
		CY2Dp(k*m + i, (k-1)*m + i) = 1/2;
		CY2Dp((k-1)*m + i, k*m + i) = 1/2;

		SY2Dp(k*m + i, (k-1)*m + i) = j/2;
		SY2Dp((k-1)*m + i, k*m + i) = -j/2;

		CY2Dnp(k*m + i, (k-1)*m + i) = 1/2;
		CY2Dnp((k-1)*m + i, k*m + i) = 1/2;

		SY2Dnp(k*m + i, (k-1)*m + i) = j/2;
		SY2Dnp((k-1)*m + i, k*m + i) = -j/2;
	endfor
% For periodic systems
	CY2Dp(i, (n-1)*m + i) = 1/2;
	CY2Dp((n-1)*m + i, i) = 1/2;

	SY2Dp(i, (n-1)*m + i) = j/2;
	SY2Dp((n-1)*m + i, i) = -j/2;
endfor

%3D matrices

%3Dx
for l= 1:p
	for k= 1:n
		for i= 1:m-1
			CX3Dp((l-1)*m*n + (k-1)*m + i + 1, (l-1)*m*n + (k-1)*m + i) = 1/2;
			CX3Dp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m + i + 1) = 1/2;

			SX3Dp((l-1)*m*n + (k-1)*m + i + 1, (l-1)*m*n + (k-1)*m + i) = j/2;
			SX3Dp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m + i + 1) = -j/2;

			CX3Dnp((l-1)*m*n + (k-1)*m + i + 1, (l-1)*m*n + (k-1)*m + i) = 1/2;
			CX3Dnp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m + i + 1) = 1/2;

			SX3Dnp((l-1)*m*n + (k-1)*m + i + 1, (l-1)*m*n + (k-1)*m + i) = j/2;
			SX3Dnp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m + i + 1) = -j/2;
		endfor
		%For periodic systems
		CX3Dp((l-1)*m*n + (k-1)*m + 1, (l-1)*m*n + (k-1)*m + n) = 1/2;
		CX3Dp((l-1)*m*n + (k-1)*m + n, (l-1)*m*n + (k-1)*m + 1) = 1/2;

		SX3Dp((l-1)*m*n + (k-1)*m + 1, (l-1)*m*n + (k-1)*m + n) = j/2;
		SX3Dp((l-1)*m*n + (k-1)*m + n, (l-1)*m*n + (k-1)*m + 1) = -j/2;
	endfor
endfor

%3Dy
for i= 1:m
	for l= 1:p
		for k= 1:n-1
			CY3Dp((l-1)*m*n + k*m + i, (l-1)*m*n + (k-1)*m +i) = 1/2;
			CY3Dp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + k*m + i) = 1/2;

			SY3Dp((l-1)*m*n + k*m + i, (l-1)*m*n + (k-1)*m +i) = j/2;
			SY3Dp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + k*m + i) = -j/2;

			CY3Dnp((l-1)*m*n + k*m + i, (l-1)*m*n + (k-1)*m +i) = 1/2;
			CY3Dnp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + k*m + i) = 1/2;

			SY3Dnp((l-1)*m*n + k*m + i, (l-1)*m*n + (k-1)*m +i) = j/2;
			SY3Dnp((l-1)*m*n + (k-1)*m + i, (l-1)*m*n + k*m + i) = -j/2;
		endfor
		%For periodic systems
		CY3Dp((l-1)*m*n + i, (l-1)*m*n + (n-1)*m +i) = 1/2;
		CY3Dp((l-1)*m*n + (n-1)*m + i, (l-1)*m*n + i) = 1/2;

		SY3Dp((l-1)*m*n + i, (l-1)*m*n + (n-1)*m +i) = j/2;
		SY3Dp((l-1)*m*n + (n-1)*m + i, (l-1)*m*n + i) = -j/2;
	endfor
endfor

%3Dz
for i = 1:m
	for k = 1:n
		for l = 1:p-1
			CZ3Dp(l*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m +i) = 1/2;
			CZ3Dp((l-1)*m*n + (k-1)*m + i, l*m*n + (k-1)*m +i) = 1/2;

			SZ3Dp(l*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m +i) = j/2;
			SZ3Dp((l-1)*m*n + (k-1)*m + i, l*m*n + (k-1)*m +i) = -j/2;

			CZ3Dnp(l*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m +i) = 1/2;
			CZ3Dnp((l-1)*m*n + (k-1)*m + i, l*m*n + (k-1)*m +i) = 1/2;

			SZ3Dnp(l*m*n + (k-1)*m + i, (l-1)*m*n + (k-1)*m +i) = j/2;
			SZ3Dnp((l-1)*m*n + (k-1)*m + i, l*m*n + (k-1)*m +i) = -j/2;
		endfor
		%For periodic systems
		CZ3Dp((k-1)*m + i, (p-1)*m*n + (k-1)*m +i) = 1/2;
		CZ3Dp((p-1)*m*n + (k-1)*m + i, (k-1)*m +i) = 1/2;

		SZ3Dp((k-1)*m + i, (p-1)*m*n + (k-1)*m +i) = j/2;
		SZ3Dp((p-1)*m*n + (k-1)*m + i, (k-1)*m +i) = -j/2;
	endfor
endfor
% CX1Dp,
% [CX1Dpvec, CX1DpLambda] = eig(CX1Dp)

% CX1Dnp,
% [CX1Dnpvec, CX1DnpLambda] = eig(CX1Dnp);

% t_x * CX1Dp + eye(m);
% B = kron(-t_x * CX1Dp + eye(m), [1,0.2;0.2,1]);
% eig(B)

% j * SX1Dp,
% CX1Dnp,
% j * SX1Dnp,
