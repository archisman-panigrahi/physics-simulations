#include <math.h>
#include "agm.h"

double agm(double a, double b)
{
	int iteration;
	double aNext, bNext, cNext;
	aNext = (a+b)/2;
	bNext = sqrt(a*b);
	cNext = (aNext - bNext)/2;

	for(iteration = 1; iteration < 30; iteration++)
	{
		
		aNext = (a+b)/2;
		bNext = sqrt(a*b);
		cNext = (cNext*cNext)/(4 * aNext);
		if(aNext == bNext)
		{
			break;
		}
		else if(cNext == 0)
		{
			break;
		}
		a = aNext;
		b = bNext;
		//printf("%d\t%.16lf\t%.16lf\t%.16lf\n", iteration, aNext, bNext, cNext);
	}
	//printf("agm = %.16lf\n",a);
	return aNext;
}