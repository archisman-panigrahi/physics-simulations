#include <math.h>

int triangleAngleArea(double a, double b, double c, double *A, double *B, double *C, double *area)
{
	double s;
	double area_square;
	s = (a+b+c)/2;
	area_square = s*(s-a)*(s-b)*(s-c);
	if(area_square < 0)
	{
		return 1;
	}
	else if(a < 0 | b < 0 | c < 0)
	{
		return 1;
	}
	else
	{	*area = sqrt(area_square);
		*A = acos((b*b+c*c-a*a)/(2*b*c));
		*B = acos((c*c+a*a-b*b)/(2*c*a));
		*C = acos((a*a+b*b-c*c)/(2*a*b));
		return 0;
	}
}