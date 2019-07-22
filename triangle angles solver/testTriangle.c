#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

void main(int argc, char *argv[])
{
	double a,b,c,area,A,B,C,check;
	check = 0;
	a = 3;
	b = 4;
	c = 5;
	if(argc > 1)
	{
		a = atof(argv[1]); //atof converts string to double
	}
	if(argc > 2)
	{
		b = atof(argv[2]);
	}
	if(argc > 3)
	{
		c = atof(argv[3]);
	}
	check = triangleAngleArea(a,b,c,&A,&B,&C,&area);
	if(check)
	{
		printf("Triangle not possible\n");
	}
	else
	{
		printf("Area is %lf\n", area);
		printf("A=%lf\tB=%lf\tC=%lf\n", A, B, C);
	}
}