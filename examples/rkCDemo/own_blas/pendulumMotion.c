#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[])
{
    double L = 1.0, g = 9.80665;
    double T0, omega0;
    double theta0_deg = 90.0, theta0, theta_sa;
    double t, y[2], ynext[2], ws[10];
    int idx, nSteps = 2000;
    PendulumData pd;
    double tStep;

    if (argc > 1)
        theta0_deg = atof(argv[1]);
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
    theta_sa = theta0;
    printf("%g %.16g %.16g\n", t, y[0], theta_sa);
    for (idx = 0; idx < nSteps; idx++) {
        stepRK4(t, y, 2, fn, &pd, ws, tStep, ynext);
        t += tStep;
        y[0] = ynext[0];
        y[1] = ynext[1];
        theta_sa = theta0 * cos(omega0 * t);
        printf("%g %.16g %.16g\n", t, y[0], theta_sa);
    }
    return 0;
}
