#include <cblas.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<lapacke.h>

void fn(double *x, int m, void *ud, double *s_out)
{
	s_out[0] = x[1] - (x[0]*x[0]);
	s_out[1] = x[1] - exp(x[0]);
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
	double *high;
	double *low;
	high = ws;
	low = ws + m;
	int i,j;
	/* This function numerically finds Jacobian
	by using df/dx = (f(x+h) - f(x-h))/(2*h)*/
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

void print_matrix(double *a,int m,int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%lf  ", a[i*n+j]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	TRIANGLE triangle;
	int i; //variable to be used in for loops
	int m=2,n=2; //size of function matrix and size of x(input) matrix

	double *ws;
	ws = (double *) malloc(sizeof(double) * (3*m)); //so far 2*m is enough
	double x[n];
	x[0] = 1;
	x[1] = 4;
	printf("Initial Guess\t");
	print_matrix(x,1,n);
	printf("\n");
	double h = 1e-8;

	double *jacob;
	jacob = (double *) malloc(sizeof(double) * (m*n));

	int iter=10;
	if(argc > 1)
		iter = atoi(argv[1]);
	double b[n];
	int ipiv[n];

	int nrhs=1,lda=n,ldb=1,info;

	for (i = 0; i < iter; ++i)
	{
		(*fn)(x,m,&triangle,b);
		findNumericalJacobian(x, fn, h, m, n, ws, &triangle, jacob);
		//printf("Function F\n");
		//print_matrix(b,1,n);
		//printf("Jacobian\n");
		//print_matrix(jacob,n,n);
		LAPACKE_dgesv(LAPACK_ROW_MAJOR,n,nrhs,jacob,lda,ipiv,b,ldb);
		//printf("JinvF\n");
		//print_matrix(b,1,n);
		cblas_daxpy(n, -1, b, 1, x, 1);
		printf("iteration %d\t", i+1);
		print_matrix(x,1,n);
	}
	return 0;
}