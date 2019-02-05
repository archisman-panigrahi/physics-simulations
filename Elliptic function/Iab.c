#include <math.h>
#include "Iab.h"

double Iab(double a, double b)
{
	if (a == b)
	{
		return (M_PI/(2*a));
	}
	int i;
	double c,d,e;
	d = a;
	e = b;
	for (i = 0; i < 15; ++i)
	{
		c = d;
		d = (d+e)/2;
		e = sqrt(c*e);
	}
	return (M_PI/(2*d));
}

double ellipticK(double k)
{
	return Iab(1, sqrt(1-(k*k)));
}