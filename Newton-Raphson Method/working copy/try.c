//Given fn, find findNumericalJacobian numerically
// #include "findNumericalJacobian.h"
#include <cblas.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void fn(double *x, int m, void *ud, double *s_out)
{
	s_out[0] = x[0]*x[1] - 1;
	s_out[1] = x[0] - x[1] - 1.5;
}

/*
df1/dx1	.........	df1/dxn
.
.
dfm/dx1 .........	dfn/dxn
*/

void findNumericalJacobian(double *x, void (*f)(double *x, int m, void *ud,double *s_out),
            double h,int m, int n, double *ws, void *udat, double *s_store)
{
	double high[m];//if this gives any error when put into
	//another file, use malloc
	double low[m];
	int i,j;
	for (i = 0; i < n; ++i)
	{
		x[i] += h;
		(*f) (x,m,udat,high); //higher value of fn is copied to high, fn is mx1 column matrix
		x[i] -= 2*h;
		(*f) (x,m,udat,low); //lower value of fn is copied to low
		for (j = 0; j < m; ++j)
		{
			s_store[j*n + i] = (high[j] - low[j]) * 0.5/h;
		}
		x[i] += h; //restore to initial value
	}
}

typedef struct _TRIANGLE {
    double xA;
    double xB;
    double xC;
    double yA;
    double yB;
    double yC;
    double ratA;
    double ratB;
    double ratC;
} TRIANGLE;

void print_matrix(double **a,int m,int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%lf  ", a[i][j]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	TRIANGLE triangle;
	int i; //variable to be used in for loops
	int m=2,n=2; //size of function matrix and size of x(input) matrix
	double ws[50];
	double x[n];
	x[0] = 1.5;
	x[1] = 0.7;

	double h = 1e-8;

	double *jacob;
	jacob = (double *) malloc(sizeof(double) * (m*n));

	findNumericalJacobian(x, fn, h, m, n, ws, &triangle, jacob);

	double b[n], ipiv[n];

	(*fn)(x,m,&triangle,b);

	int nrhs=1,lda=n,ldb=n,info; //don't put ldb = 1;
	double a[1];
	a[0] = 3;
	for (i = 0; i < 10; ++i)
	{
		(*fn)(x,m,&triangle,b);
		findNumericalJacobian(x, fn, h, m, n, ws, &triangle, jacob);
		dgesv_(&n,&nrhs,jacob,&lda,ipiv,b,&ldb,&info);
		cblas_daxpy(n, -1, b, 1, x, 1);

		printf("%lf	%lf\n", x[0], x[1]);
	}
	return 0;
}