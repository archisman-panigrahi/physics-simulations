#include "blas.h"

/* Copy one vector to another: dst = src */
void cblas_dcopy(int m, double *src, int incSrc, double *dst, int incDst)
{
    int idx, idxSrc, idxDst;
    for (idxSrc = idxDst = idx = 0; idx < m; idx++) {
        dst[idxDst] = src[idxSrc];
        idxSrc += incSrc;
        idxDst += incDst;
    }
}

/* Add ax to y and store in y:  y = a*x + y */
void cblas_daxpy(int m, double a, double *x, int incX, double *y, int incY)
{
    int idx, idxX, idxY;
    for (idxX = idxY = idx = 0; idx < m; idx++) {
        y[idxY] += a * x[idxX];
        idxX += incX;
        idxY += incY;
    }
}
