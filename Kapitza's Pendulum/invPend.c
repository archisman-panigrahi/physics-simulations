#include <stdio.h>
#include <math.h>
#include "invPend.h"
#include "ode.h"

typedef struct _InvPendParams {
	double l;
	double g;
	double a;
	double omega;
} InvPendParams;

void fn(double t, double *u, int m, void *udat, double *s_out) {
	InvPendParams *ip = (InvPendParams *) udat;
	s_out[0] = u[1];
	s_out[1] = (ip->g - ip->a * ip->omega * ip->omega * sin(ip->omega * t)) * sin(u[0]) / ip->l;
}


void InvPend_motion(double l, double g, double a, double omega,
	double theta_0, double v_theta_0, int nSteps, double finalTime)
{

	InvPendParams ip;
	ip.l = l;
	ip.g = g;
	ip.a = a;
	ip.omega = omega;
	
	double t = 0, y[2], ynext[2], ws[10];
	int idx;

	y[0] = theta_0; //initial theta coordinate
	y[1] = v_theta_0; //initial v_theta coordinate


	FILE *datafile;
	datafile = fopen("output.dat","w+");

	double tStep = (finalTime/nSteps);
	/* Print in for loop*/
	for (idx = 0; idx < nSteps; idx++)
	{
		stepRK4(t, y, 2, fn, &ip, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		fprintf(datafile, "%lf\t%lf\t%lf\n", t, y[0], y[1]);
	}
}