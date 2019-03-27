#ifndef _TRIANGLERATIO_INC_
#define _TRIANGLERATIO_INC_

#ifdef __cplusplus
extern "C" {
#endif

double findDistance(double xA, double xB, double yA, double yB);
void triangleRatio(double xA, double xB, double xC, 
					double yA, double yB, double yC, 
					double ratA, double ratB, double ratC);
void fn(double *x, int m, void *ud, double *s_out);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_ODE_INC_) */
