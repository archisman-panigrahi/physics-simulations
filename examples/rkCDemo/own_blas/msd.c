#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blas.h"
#include "ode.h"

typedef struct _MSD {
    double m;
    double b;
    double k;
    double alpha;
    double omega_0;
    double omega_d;
    double x0;
} MSD;

void fn(double x, double *y, int m, void *udat, double *s)
{
    MSD *msd;
    msd = (MSD *)udat;
    s[0] = y[1];
    s[1] = - (msd->b*y[1] + msd->k*y[0])/msd->m;
}

int main(int argc, char *argv[])
{
    MSD msd;
    double t, tMin = 0.0, tMax = 8.0;
    double yRK1[2], yRK2[2], yRK4[2];
    double yNew[2];
    double xExact;
    double ws[4];
    double h, phi;
    int i, nSteps = 100;
    msd.k = 10;
    msd.m = 1;
    msd.b = 0.1;
    msd.x0 = 1.0;
    if (argc > 1)
        nSteps = atoi(argv[1]);
    if (argc > 2)
        tMax = atof(argv[2]);
    if (argc > 3)
        msd.m = atof(argv[3]);
    if (argc > 4)
        msd.b = atof(argv[4]);
    if (argc > 5)
        msd.k = atof(argv[5]);
    msd.alpha = 0.5*msd.b/msd.m;
    msd.omega_0 = sqrt(msd.k/msd.m);
    msd.omega_d = sqrt(msd.k/msd.m - msd.alpha * msd.alpha);
    h = (tMax - tMin)/nSteps;
    t = tMin;
    yRK1[0] = msd.x0;
    yRK1[1] = 0.0;
    yRK2[0] = msd.x0;
    yRK2[1] = 0.0;
    yRK4[0] = msd.x0;
    yRK4[1] = 0.0;
    xExact = msd.x0;
    printf("%g %.16g %.16g %.16g %.16g\n",
        t, yRK1[0], yRK2[0], yRK4[0], xExact);
    for (i=0; i < nSteps; i++) {
        stepRK1(t, yRK1, 2, fn, &msd, ws, 0.25*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK1, 1);
        stepRK1(t+0.25*h, yRK1, 2, fn, &msd, ws, 0.25*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK1, 1);
        stepRK1(t+0.5*h, yRK1, 2, fn, &msd, ws, 0.25*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK1, 1);
        stepRK1(t+0.75*h, yRK1, 2, fn, &msd, ws, 0.25*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK1, 1);

        stepRK2(t, yRK2, 2, fn, &msd, ws, 0.5*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK2, 1);
        stepRK2(t+0.5*h, yRK2, 2, fn, &msd, ws, 0.5*h, yNew);
        cblas_dcopy(2, yNew, 1, yRK2, 1);

        stepRK4(t, yRK4, 2, fn, &msd, ws, h, yNew);
        cblas_dcopy(2, yNew, 1, yRK4, 1);

        t += h;
        phi = msd.omega_d * t;
        xExact = msd.x0 * exp(-msd.alpha*t)
                    * (cos(phi) + sin(phi) * msd.alpha/msd.omega_d);
        printf("%g %.16g %.16g %.16g %.16g\n",
                    t, yRK1[0], yRK2[0], yRK4[0], xExact);
    }
    return 0;
}
