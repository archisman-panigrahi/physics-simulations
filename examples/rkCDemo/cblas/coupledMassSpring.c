#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>
#include "ode.h"

void arraySetZero(int n, double *x)
{
    int i;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
}

typedef struct _CoupledMassSpring {
    double m;
    double k_A;
    double k_B;
    double omega_1;
    double omega_2;
    double rSelf;
    double rCross;
} CoupledMassSpring;

static int nfe = 0;

void fn(double t, double *y, int m, void *udat, double *s)
{
    CoupledMassSpring *cms;
    cms = (CoupledMassSpring *)udat;
    s[0] = y[2];
    s[1] = y[3];
    s[2] = -cms->rSelf * y[0] + cms->rCross * y[1];
    s[3] = -cms->rSelf * y[1] + cms->rCross * y[0];
    nfe++;
}

int main(int argc, char *argv[])
{
    CoupledMassSpring cms;
    double t, tMin = 0.0, tMax;
    double y[4];
    double yNew[4];
    double ws[8];
    double h;
    double x_1_0, x_2_0, u_1_0, u_2_0, x1Exact;
    int i, nSteps = 400, nCycles = 8;
    char *epTxt;

    cms.m = 1.0;
    cms.k_A = 1.0;
    cms.k_B = 1.0;

    epTxt = getenv("CMS_M");
    if (epTxt != NULL)
        cms.m = atof(epTxt);
    epTxt = getenv("CMS_KA");
    if (epTxt != NULL)
        cms.k_A = atof(epTxt);
    epTxt = getenv("CMS_KB");
    if (epTxt != NULL)
        cms.k_B = atof(epTxt);
    epTxt = getenv("CMS_NSTEPS");
    if (epTxt != NULL)
        nSteps = atoi(epTxt);
    epTxt = getenv("CMS_NCYCLES");
    if (epTxt != NULL)
        nCycles = atoi(epTxt);

    cms.omega_1 = sqrt(cms.k_A/cms.m);
    cms.omega_2 = sqrt((cms.k_A + 2*cms.k_B)/cms.m);
    cms.rSelf = (cms.k_A + cms.k_B)/cms.m;
    cms.rCross = cms.k_B/cms.m;
    tMax = nCycles * 2.0 * M_PI / cms.omega_1;
    h = (tMax - tMin)/nSteps;
    t = tMin;
    x_1_0 = 1.0;
    x_2_0 = x_1_0 * cms.k_B/(cms.k_A + cms.k_B);
    u_1_0 = x_1_0 + x_2_0;
    u_2_0 = x_1_0 - x_2_0;
    arraySetZero(4, y);
    y[0] = x_1_0;
    y[1] = x_2_0;
    printf("%g %.16g %.16g\n", tMin, x_1_0, x_1_0);
    for (i=0; i < nSteps; i++) {
        stepRK4(t, y, 4, fn, &cms, ws, h, yNew);
        cblas_dcopy(4, yNew, 1, y, 1);
        t += h;
        x1Exact = 0.5 * (u_1_0 * cos(cms.omega_1 * t)
                           +  u_2_0 * cos(cms.omega_2 * t));
        printf("%g %.16g %.16g\n", t, y[0], x1Exact);
    }
    fprintf(stderr, "NFE = %d\n", nfe);
    fprintf(stderr, "h*omega2 = %g\n", h*cms.omega_2);
    return 0;
}
