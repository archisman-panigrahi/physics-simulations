#include "jacobian.h"
#include <math.h>
void findNumericalJacobian(double *x, void (*f)(double *x, int m, void *ud,double *s_out),
            double h,int m, int n, double *ws, void *udat, double *s_store)
{
	double *high;
	double *low;
	high = ws;
	low = ws + m;
	int iCol,iRow;
	/* This function numerically finds Jacobian
	by using df/dx = (f(x+h) - f(x-h))/(2*h)*/
	for (iCol = 0; iCol < n; ++iCol)
	{
		x[iCol] += h;
		(*f) (x,m,udat,high); //higher value of fn is copied to high, fn is mx1 column matrix
		x[iCol] -= 2*h;
		(*f) (x,m,udat,low); //lower value of fn is copied to low
		for (iRow = 0; iRow < m; ++iRow)
		{
			s_store[iRow*n + iCol] = (high[iRow] - low[iRow]) * 0.5/h;
		}
		x[iCol] += h; //restore to initial value
	}
}