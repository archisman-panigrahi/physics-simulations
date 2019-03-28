#ifndef _DISTANCERATIO_INC_
#define _DISTANCERATIO_INC_

#ifdef __cplusplus
extern "C" {
#endif

double findDistance(double xA, double xB, double yA, double yB);
void triangleRatio(double xA, double xB, double xC, 
					double yA, double yB, double yC, 
					double ratA, double ratB, double ratC);
void fn(double *x, int m, void *ud, double *s_out);
double hav(double x);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_DISTANCERATIO_INC_) */
