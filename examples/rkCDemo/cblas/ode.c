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
    cblas_daxpy(m, b1*h, S, 1, yNext, 1); //yNext is y + k1 (which is S) times h/4
    cblas_dcopy(m, y, 1, ytmp, 1); //ytmp is y
    cblas_daxpy(m, a21*h, S, 1, ytmp, 1); // ytmp is y + 2/3 h k1
    (*f)(x + c2*h, ytmp, m, udat, S); /* S is now S2 */
    cblas_daxpy(m, b2*h, S, 1, yNext, 1); // yNext is y + k1 * h/4 + k2 * 3h/4
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

    cblas_dcopy(m, y, 1, yNext, 1); //yNext is y
    (*f)(x, y, m, udat, S); /* S is now S1 */ //k1 = f(x,y) is evaluated
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1); //yNext is y + h/6 * k1
    cblas_dcopy(m, y, 1, ytmp, 1); // ytmp is y
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1); // ytmp is y + 0.5*h*k1
    (*f)(x+0.5*h, ytmp, m, udat, S); /* S is now S2 */ //k2 = f(x+h/2,y+h*k1/6) is evaluated
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1); //yNext is y + h/6 * k1 + h/3 * k2 
    cblas_dcopy(m, y, 1, ytmp, 1); //ytmp is y
    cblas_daxpy(m, 0.5*h, S, 1, ytmp, 1); // ytmp is y + h/2 * k2
    (*f)(x+0.5*h, ytmp, m, udat, S); /* S is now S3 */ //k3 = f(x + h/2, y + k2/2) is evaluated
    cblas_daxpy(m, h/3.0, S, 1, yNext, 1); //yNext is y + h/6 * k1 + h/3 * k2 + h/3 * k3
    cblas_dcopy(m, y, 1, ytmp, 1); //ytmp is y
    cblas_daxpy(m, h, S, 1, ytmp, 1); //ytmp is y + h * k3
    (*f)(x+h, ytmp, m, udat, S); /* S is now S4 */ //k4 = f(x + h, y + k) is evaluated
    cblas_daxpy(m, h/6.0, S, 1, yNext, 1); //yNext is now y + h/6 * k1 + h/3 * k2 + h/3 * k3 + h/6 * k4
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
