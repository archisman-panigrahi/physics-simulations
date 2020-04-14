%Represent quantum number j by q, m by r

Jz = zeros(2*q + 1, 2*q + 1);
J_minus = zeros(2*q + 1, 2*q +1);
r = q;
for i=1:(2*q)
	Jz(i,i) = r;
	J_minus(i+1,i) = sqrt(q*(q+1) - r*(r-1));
	r = r-1;
endfor
Jz(2*q+1,2*q+1) = -q;
J_plus = transpose(J_minus);%dagger

Jx = (J_plus + J_minus)/2;
Jy = (J_plus - J_minus)/(2*j);

clear r;