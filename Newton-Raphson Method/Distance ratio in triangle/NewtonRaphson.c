#include "NewtonRaphson.h"
#include "jacobian.h"
#include <cblas.h>
#include <stdlib.h>
#include <math.h>

int NewtonRaphson(double *x, 
	void (*fn)(double *x, int m, void *ud, double *s_out),
	double h, int n, double *ws, int iter, void *udat, double tolerance) 
{
	int i;
	double *b;
	double *ipiv;
	b = (double *) malloc(sizeof(double) * (n));
	ipiv = (double *) malloc(sizeof(double) * (n));
	double *jacob;
	jacob =  (double *) malloc(sizeof(double) * (n*n));
	int lda = n, nrhs = 1, ldb = n, info;

	for (i = 0; i < iter; ++i)
	{
		(*fn)(x,n,udat,b);
		findNumericalJacobian(x, fn, h, n, n, ws, udat, jacob); //if not try &udat
		dgesv_(&n,&nrhs,jacob,&lda,ipiv,b,&ldb,&info);
		cblas_daxpy(n, -1, b, 1, x, 1);
	}
	if (normVector(b,n) <= tolerance)
	{
		return 1; //success
	}
	else
	{
		return 0; //does not converge after n iterations
	}
}
double normVector(double *b, int n)
{
	double length = 0;
	for (int i = 0; i < n; ++i)
	{
		length += b[i]*b[i];
	}
	return sqrt(length);
}