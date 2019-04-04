#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double integrand(double x)
{
	return (cos(x)/((x*x)+1));
}
int main(int argc, char const *argv[])
{
	double a = 1, b = 5;
	double steps = 10000000;

	double integral = 0;

	if(argc > 1)
		a = atof(argv[1]);
	if(argc > 2)
		b = atof(argv[2]);
	if(argc > 3)
		steps = atof(argv[3]);
	double h = (b-a)/steps;
	for (int i = 1; i < steps+1; ++i)
	{
		integral += integrand(a + (i*h)) * h;
	}
	printf("%lf\n", integral);
	return 0;
}