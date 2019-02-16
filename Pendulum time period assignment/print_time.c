#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ellint.h"
#include "pendulum_RK_time.h"

int main(int argc, char const *argv[])
{
	double L = 1, g = 9.80665;
	double theta0_deg = 90;
	double theta0, T0;
	double Tnum, Texact;

	if (argc > 1)
	{
		theta0_deg = atof(argv[1]);
		if (theta0_deg < 0)
		{
			theta0_deg = -(theta0_deg);
		}
		else if(theta0_deg > 180)
		{
			printf("Initial angle should be less than or equal to 180 degree\n");
			printf("Type ./pendulum_time_period angle(in degree) L(optional) g(optional)\n");
			return 0;
		}
		else if(theta0_deg == 0)
		{
			printf("Pendulum won't move\n");
			printf("Type ./pendulum_time_period angle(in degree) L(optional) g(optional)\n");
			return 0;
		}
	}
	if (argc > 2)
	{
		L = atof(argv[2]);
	}
	if (argc > 3)
	{
		g = atof(argv[3]);
	}
	Tnum = pendulum_RK4_time(L,g,theta0_deg,&theta0,&T0);
	Texact = 4*ellipK(sin(theta0/2)) * sqrt(L/g);

    printf("\ntheta0_deg = %lf degree\n", theta0_deg);
    printf("Numeric(RK4) time period = %.16lf s\n", Tnum);
    printf("Analytic time period = %.16lf s\n", Texact);
    printf("Error (Numeric - Analytic) = %.16g s\n", Tnum - Texact);
    printf("T0 (small angle approx. time period) = %.16lf s\n",T0);
    printf("Texact/T0 = %.16lf\n\n", Texact/T0);

	return 0;
}