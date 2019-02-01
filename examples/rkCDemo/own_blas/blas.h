#ifndef _BLAS_INC_
#define _BLAS_INC_

#ifdef __cplusplus
extern "C" {
#endif

void cblas_dcopy(int m, double *src, int incSrc, double *dst, int incDst);
void cblas_daxpy(int m, double a, double *x, int incX, double *y, int incY);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_BLAS_INC_) */
