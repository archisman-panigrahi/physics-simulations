#include <stdlib.h>
#include <math.h>

#define PI 3.141592654
double gaussrand()
{
	static double U, V;
	static int phase = 0;
	double z;
	
	if (phase == 0) {
		U = (rand() * 1.) / (RAND_MAX + 2.);
		V = rand() / (RAND_MAX + 1.);
		z = sqrt(-2 * log(U)) * sin(2 * PI * V);
	}
	else
	{
		z = sqrt(-2 * log(U)) * cos(2 * PI * V);
	}
	phase = 1 - phase;
	return z;
}
