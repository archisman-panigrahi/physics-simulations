#include <math.h>
#include "ode.h"

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

double pendulum_RK4_time(double L, double g, double theta0_deg, double *theta0, double *T0)
{
    PendulumData pd;

    pd.L = L;
    pd.g = g;
    pd.gOverL = g / L;


    //double omega0 = sqrt(pd.gOverL);
    *T0 = 2.0 * M_PI / sqrt(pd.gOverL);
    *theta0 = theta0_deg * M_PI / 180.0;
    double t, y[2], ynext[2], ws[10];
    int idx, nSteps = 2000;
    
    double tStep;
    double Tnum;


    tStep = 2.0 * (*T0 / nSteps);
    y[0] = *theta0;
    y[1] = 0.0;
    t = 0.0;

    for (idx = 0; ; idx++) {
        stepRK4(t, y, 2, fn, &pd, ws, tStep, ynext);
        if(ynext[0] < 0)
        {	
        	if (y[0] > 0)
        		{
        			Tnum = 4 * ((t) + (y[0] * tStep/(y[0]-ynext[0])));
                    return Tnum;
        		}
        }
        t += tStep;
        
        y[0] = ynext[0];
        y[1] = ynext[1];
    }
}
