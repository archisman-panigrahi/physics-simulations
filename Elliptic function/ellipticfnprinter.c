#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Iab.h"

int main(int argc, char const *argv[])
{
	double a,i;
	FILE *data;
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
	data = fopen("data.csv","w+");
	fprintf(data, "x\tK(x)\n");
	for (i = 0; i < a; ++i)
	{
		fprintf(data, "%.16lf\t%.16lf\n", i/a, ellipticK(i/a));
	}
	return 0;
}