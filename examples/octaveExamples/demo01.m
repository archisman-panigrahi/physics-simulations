more off;
% Enter matrices element by element
A = [3, 1, 1; 1, 3, 1; 1, 1, 3]
b = [5; 5; 5]
x = A \ b

eig(A)

% Creating matrices by commands
K = eye(4)
M = ones(2, 3)

H = hilb(5)
cond(H)

% Elements of a matrix
H(2,3)
b(3)

% Submatrix: Part of a matrix
F = H(2:3, 3:5)
G = H(2:3, :)
W = H([5, 1], [5, 3, 1])

