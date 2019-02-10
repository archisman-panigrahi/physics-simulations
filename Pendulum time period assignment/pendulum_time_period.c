#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ode.h"
#include "ellint.h"

typedef struct _PendulumData {
    double gOverL;
    double g;
    double L;
} PendulumData;

void fn(double t, double *y, int m, void *udat, double *s_out)
{
    PendulumData *p;
    p = (PendulumData *)udat;
    s_out[0] = y[1];
    s_out[1] = -(p->gOverL) *sin(y[0]);
}

int main(int argc, char *argv[])
{
    double L = 1.0, g = 9.80665;
    double T0, omega0;
    double theta0_deg = 90.0, theta0;
    double t, y[2], ynext[2], ws[10];
    int idx, nSteps = 2000;
    PendulumData pd;
    double tStep;
    double Tnum, Texact;

    if (argc > 1)
    {
        theta0_deg = atof(argv[1]);
        if (theta0_deg < 0)
            theta0_deg = -(theta0_deg);
        if(theta0_deg > 180)
        {
            printf("Initial angle should be less than or equal to 180 degree\n");
            printf("Type pendulum_time_period angle(in degree) L(optional) g(optional)\n");
            return 0;
        }
        else if(theta0_deg == 0)
        {
            printf("Pendulum won't move\n");
            printf("Type pendulum_time_period angle(in degree) L(optional) g(optional)\n");
            return 0;
        }
    }
    if (argc > 2)
        L = atof(argv[2]);
    if (argc > 3)
        g = atof(argv[3]);

    pd.L = L;
    pd.g = g;
    pd.gOverL = g / L;

    theta0 = theta0_deg * M_PI / 180.0;
    omega0 = sqrt(pd.gOverL);
    T0 = 2.0 * M_PI / omega0;
    tStep = 2.0 * T0 / nSteps;
    y[0] = theta0;
    y[1] = 0.0;
    t = 0.0;

    for (idx = 0; ; idx++) {
        stepRK4(t, y, 2, fn, &pd, ws, tStep, ynext);
        if(ynext[0] < 0)
        {	
        	if (y[0] > 0)
        		{
        			Tnum = (t) + (y[0] * tStep/(y[0]-ynext[0]));
        			break;
        		}
        }
        t += tStep;
        
        y[0] = ynext[0];
        y[1] = ynext[1];
    }
    Texact = 4*ellipK(sin(theta0/2))/omega0;
    printf("\ntheta0 = %lf degree\n", theta0_deg);
    printf("Numeric time period = %.16lf s\n", 4*Tnum);
    printf("Analytic time period = %.16lf s\n", Texact);
    printf("Error (Numeric - Analytic) = %.16g s\n", (4 * Tnum) - Texact);
    printf("T0 = %.16lf s\n",T0);
    printf("Texact/T0 = %.16lf\n\n", Texact/T0);
    return 0;
}
