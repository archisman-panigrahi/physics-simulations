#include "distanceRatio.h"
#include <math.h>
#include <stdio.h>
#include "NewtonRaphson.h"

typedef struct _ratioData {
	double latA;
	double longA;
	double latB;
	double longB;
	double latC;
	double longC;
	double ratA;
	double ratB;
	double ratC;
} ratioData;

void fn(double *x, int m, void *ud, double *s_out)
{
	ratioData *triangle;
	triangle = (ratioData *)ud;
	double AP = findDistance(triangle->latA,x[0],triangle->longA,x[1]);
	double BP = findDistance(triangle->latB,x[0],triangle->longB,x[1]);
	double CP = findDistance(triangle->latC,x[0],triangle->longC,x[1]);
	s_out[0] = (triangle->ratB * AP) - (triangle->ratA * BP); //b*AP - a*BP = 0
	s_out[1] = (triangle->ratC * AP) - (triangle->ratA * CP); //c*AP - a*CP = 0
}

double findDistance(double latA, double latB, double longA, double longB)
{
	double hav_delta_sigma;
	hav_delta_sigma = hav(latA - latB) + cos(latA) * cos(latB) * hav(longA - longB);
	return (2 * asin(sqrt(hav_delta_sigma)));
}

double hav(double x)
{
	return (sin(x/2) * sin(x/2));
}

void triangleRatio(double latA, double latB, double latC, double longA, double longB, double longC, double ratA, double ratB, double ratC)
{
	//print input
	printf("Input points(lat,long):\n");
	printf("A(%lf,%lf)\t", latA, longA);
	printf("B(%lf,%lf)\t", latB, longB);
	printf("C(%lf,%lf)\n\n", latC, longC);
	//convert to radian
	latA = (M_PI/180) * latA;
	latB = (M_PI/180) * latB;
	latC = (M_PI/180) * latC;
	longA = (M_PI/180) * longA;
	longB = (M_PI/180) * longB;
	longC = (M_PI/180) * longC;


	double x[2];
	//initial guess
	x[0] = (latA + latB + latC)/3;
	x[1] = (longA + longB + longC)/3;
	//printf("x.init = %lf  y.init = %lf\n", x[0], x[1]);
	int n = 2, iter = 30;
	double ws[4];
	double tolerance = 1e-6;
	double h = 1e-8;


	ratioData tri;

	tri.latA = latA;
	tri.latB = latB;
	tri.latC = latC;
	tri.longA = longA;
	tri.longB = longB;
	tri.longC = longC;
	tri.ratA = ratA;
	tri.ratB = ratB;
	tri.ratC = ratC;

	int success = NewtonRaphson(x,fn,h,n,ws,&iter,&tri,tolerance);

	if (success == 0)
	{
		printf("Does not converge upto 6 decimal place after %d iterations\n\n",iter);
	}
	if (success == 1)
	{
		printf("Converges to at least 6 decimal places after %d iterations\n\n", iter);
	}

	printf("Output:\n");
	printf("solution point P(%lf,%lf)\n",(180/M_PI)*x[0],(180/M_PI)*x[1]);

	double AP = 6371*findDistance(latA,x[0],longA,x[1]);
	double BP = 6371*findDistance(latB,x[0],longB,x[1]);
	double CP = 6371*findDistance(latC,x[0],longC,x[1]);

	printf("AP = %lf KM, BP = %lf KM, CP = %lf KM\n", AP, BP, CP);
	printf("AP/%lf = %lf, BP/%lf = %lf, CP/%lf = %lf\n", ratA, (AP/ratA), ratB, (BP/ratB), ratC, (CP/ratC));

}