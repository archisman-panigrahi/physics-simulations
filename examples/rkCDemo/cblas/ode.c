#include <cblas.h>
#include "ode.h"

void stepRK1(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext )
{
    double *S1;

    S1 = ws;
    (*f)(x, y, m, udat, S1);
    cblas_dcopy(m, y, 1, yNext, 1);
    cblas_daxpy(m, h, S1, 1, yNext, 1);
}

void stepRK1NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext )
{
    double *S1;

    S1 = ws;
    (*f)(x, y, m, S1);
    cblas_dcopy(m, y, 1, yNext, 1);
    cblas_daxpy(m, h, S1, 1, yNext, 1);
}

void stepRK2(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext )
{
    double *S, *ytmp;
    double c2 = 2.0 / 3.0;
    double b1 = 0.25, b2 = 0.75;
    double a21;

    a21 = c2;
    S = ws;
    ytmp = &S[m];

    cblas_dcopy(m, y, 1, yNext, 1);
    (*f)(x, y, m, udat, S); /* S is now S1 */ 
    cblas_daxpy(m, b1*h, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, a21*h, S, 1, ytmp, 1);
    (*f)(x + c2*h, ytmp, m, udat, S); /* S is now S2 */
    cblas_daxpy(m, b2*h, S, 1, yNext, 1);
}

void stepRK2NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext )
{
    double *S, *ytmp;
    double c2 = 2.0 / 3.0;
    double b1 = 0.25, b2 = 0.75;
    double a21;

    a21 = c2;
    S = ws;
    ytmp = &S[m];

    cblas_dcopy(m, y, 1, yNext, 1);
    (*f)(x, y, m, S); /* S is now S1 */ 
    cblas_daxpy(m, b1*h, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, a21*h, S, 1, ytmp, 1);
    (*f)(x + c2*h, ytmp, m, S); /* S is now S2 */ 
    cblas_daxpy(m, b2*h, S, 1, yNext, 1);
}

void stepRK4(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext )
{
    double *S, *ytmp;

    S = ws;
    ytmp = &S[m];

    cblas_dcopy(m, y, 1, yNext, 1);
    (*f)(x, y, m, udat, S); /* S is now S1 */
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1);
    (*f)(x+0.5*h, ytmp, m, udat, S); /* S is now S2 */
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1);
    (*f)(x+0.5*h, ytmp, m, udat, S); /* S is now S3 */
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, h, S, 1, ytmp, 1);
    (*f)(x+h, ytmp, m, udat, S); /* S is now S4 */
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1);
}

void stepRK4NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext )
{
    double *S, *ytmp;

    S = ws;
    ytmp = &S[m];

    cblas_dcopy(m, y, 1, yNext, 1);
    (*f)(x, y, m, S); /* S is now S1 */
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1);
    (*f)(x+0.5*h, ytmp, m, S); /* S is now S2 */
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1);
    (*f)(x+0.5*h, ytmp, m, S); /* S is now S3 */
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1);
    cblas_dcopy(m, y, 1, ytmp, 1);
    cblas_daxpy(m, h, S, 1, ytmp, 1);
    (*f)(x+h, ytmp, m, S); /* S is now S4 */
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1);
}
