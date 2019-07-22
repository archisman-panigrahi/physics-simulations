#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi = 3.14159265359;
int triangleAngleArea(double a, double b, double c, double *A, double *B, double *C, double *area)
{
	double s;
	s = (a+b+c)/2;
	*area = s*(s-a)*(s-b)*(s-c);
	if(*area <= 0)
		return 1;
	else
		*A = acos((b*b+c*c-a*a)/(2*b*c)); //Note: *A = acos((b*b+c*c-a*a)/2*b*c); gives nan
		*B = acos((c*c+a*a-b*b)/(2*c*a));
		*C = acos((a*a+b*b-c*c)/(2*a*b));
		return 0;
}
void main(int argc, char *argv[])
{
	double a,b,c,area,A,B,C;
	int check;
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);


	printf("a= %lf b= %lf c= %lf \n", a,b,c);
	check = triangleAngleArea(a,b,c,&A,&B,&C,&area);
	if(check == 1)
	{
		printf("Triangle not possible\n");
		return;
	}
	else
	{
		printf("area is %lf\n", sqrt(area));
		printf("%lf\t%lf\t%lf\n", A, B, C);
		printf("%lf\t%lf\t%lf\n", (180*A/pi), (180*B/pi), (180*C/pi));
	}
}