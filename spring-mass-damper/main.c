#include <stdio.h>
#include <stdlib.h>
#include "smd.h"
void main(int argc, char const *argv[])
{
	long double x,v,x_0 = 1,v_0 = 1,k = 4,m = 1,b = .1,t_f = 5,iterations = 10000;
	int print_to_file = 0;
	printf("Note: Run ./spring_mass_damper x_0 v_0 m b k t_f iterations print_to_file\n");
	if(argc > 1)
	{	
		x_0 = atof(argv[1]);
	}
	printf("x_0 = %Lf\n", x_0);
	if(argc > 2)
	{	
		v_0 = atof(argv[2]);
	}
	printf("v_0 = %Lf\n", v_0);
	if(argc > 3)
	{	
		m = atof(argv[3]);
	}
	printf("m = %Lf\n", m);
	if(argc > 4)
	{	
		b = atof(argv[4]);
	}
	printf("b = %Lf\n", b);
	if(argc > 5)
	{	
		k = atof(argv[5]);
	}
	printf("k = %Lf\n", k);
	if(argc > 6)
	{	
		t_f = atof(argv[6]);
	}
	printf("t_f = %Lf\n", t_f);
	if(argc > 7)
	{	
		iterations = atof(argv[7]);
	}
	if(argc > 8)
	{
		print_to_file = atof(argv[8]);
	}
	printf("iterations = %Lf\n", iterations);
	if(smd(x_0,v_0,m,b,k,t_f,iterations,&x,&v,0) == 1)
	{	printf("Wrong data - m and b cannot be simultaneously 0\n");
		return;
	}
	printf("x = %Lf, v = %Lf at t = %Lf \n", x, v, t_f);
	return ;
}