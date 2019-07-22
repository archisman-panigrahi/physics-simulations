#ifndef _ODE_INC_
#define _ODE_INC_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*RKStepperFn)(double x, double *y, int m,
              void (*f)(double x, double *y, int m, void *ud, double *s_out),
                void *udat, double *ws, double h, double *yNext );
typedef void (*RKStepperFnNoPar)(double x, double *y, int m,
                void (*f)(double x, double *y, int m, double *s_out),
                  double *ws, double h, double *yNext );

/**
 * Euler Forward Step ODE solver for
 *
 *    dy
 *   ---- = f(x, y)
 *    dx 
 *
 * Arguments:
 *   x: Independent variable
 *   y: Dependent variable vector
 *   m: Number of components of y
 *   f: Pointer to slope function
 *        Arguments of f: x, y, m, udat, s_out
 *                        s_out: Array where the slope vector is stored
 *   udat: Parameters (user data) needed for evaluating the slope
 *         function f
 *   ws: Workspace array which should be of size at least 2m
 *   h: x step
 *   yNext: Array for holding the next value of y
 */
void stepRK1(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext );
void stepRK1NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext );

void stepRK2(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext );
void stepRK2NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext );

void stepRK4(double x, double *y, int m,
               void (*f)(double x, double *y, int m, void *ud, double *s_out),
                 void *udat, double *ws, double h, double *yNext );
void stepRK4NP(double x, double *y, int m,
                 void (*f)(double x, double *y, int m, double *s_out),
                   double *ws, double h, double *yNext );

#ifdef __cplusplus
}
#endif

#endif /* !defined(_ODE_INC_) */
