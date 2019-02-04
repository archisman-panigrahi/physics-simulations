#include <math.h>
#include "am.h"
#include "gm.h"
#include "Iab.h"

double Iab(double a, double b)
{
	int i;
	double c,d,e;
	d = a;
	e = b;
	for (i = 0; i < 15; ++i)
	{
		c = d;
		d = am(d,e);
		e = gm(c,e);
	}
	return (M_PI/(2*d));
}

double ellipticK(double k)
{
	return Iab(1, sqrt(1-(k*k)));
}