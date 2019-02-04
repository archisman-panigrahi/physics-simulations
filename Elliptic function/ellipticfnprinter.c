#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Iab.h"

int main(int argc, char const *argv[])
{
	double a,i;
	a = 100;
	if (argc > 1)
	{
		a = atof(argv[1]);
		if (a == 0)
		{
			printf("This was no of steps. Using 100 instead\n");
			a = 100;
		}
	}
	printf("x\tK(x)\n");
	for (i = 0; i < a; ++i)
	{
		printf("%lf\t%.16lf\n", i/a, ellipticK(i/a));
	}
	return 0;
}