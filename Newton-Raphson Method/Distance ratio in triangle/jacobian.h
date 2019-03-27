#ifndef _JACOBIAN_INC_
#define _JACOBIAN_INC_

#ifdef __cplusplus
extern "C" {
#endif
void findNumericalJacobian(double *x, void (*f)(double *x, int m, void *ud,double *s_out),
		double h,int m, int n, double *ws, void *udat, double *s_store);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_JACOBIAN_INC_) */