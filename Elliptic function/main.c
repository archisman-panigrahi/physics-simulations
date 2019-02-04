#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Iab.h"



int main(int argc, char const *argv[])
{
	double a,b;
	a = 0.5;
	b = 0.5;
	if (argc > 1)
	{
		a = atof(argv[1]);
	}

	if (argc > 2)
	{
		b = atof(argv[2]);
	}

	if (a == 0)
	{
		if(b >= 1)
		{
			printf("Error k=%lf, which should be less than 1\n", b);
			return 0;
		}
		printf("K(%lf) = %.16lf\n", b, ellipticK(b));
		return 0;
	}
	printf("a=%lf, b=%lf\n", a,b);
	printf("%.16lf\n", Iab(a,b));
	return 0;
}