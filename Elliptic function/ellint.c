#include <math.h>
#include "agm.h"
#include "ellint.h"

double Iab(double a, double b)
{
	return (M_PI/(2*agm(a,b)));
}

double ellipK(double k)
{
	if(k >= 1 || k <= -1)
		return 1.0/0.0;
	return (M_PI/(2*agm(1+k, 1-k)));
}