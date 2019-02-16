#ifndef _pendulum_RK_time_INC_
#define _pendulum_RK_time_INC_

#ifdef __cplusplus
extern "C" {
#endif

double pendulum_RK4_time(double L, double g, double theta0_deg, double *theta0, double *T0);
void fn(double t, double *y, int m, void *udat, double *s_out);


/**
 * Returns time period of pendulum of length L kept at 
 * gravitational field g at initial angle theta0_deg (in degrees)
 * It also changes *theta0 (initial angle in radian) 
 * and *T0 (small angle approximated time period).
**/

#ifdef __cplusplus
}
#endif

#endif /* !defined(_pendulum_RK_time_INC_) */
