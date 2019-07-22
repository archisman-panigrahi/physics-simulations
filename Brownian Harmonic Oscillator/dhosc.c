#include <stdio.h>
#include <math.h>
#include "dhosc.h"
#include "ode.h"
#include "random.h"

typedef struct _DampedHarmonicOscParams {
	double omega;
	double gamma;
	double squeeze;
} DampedHarmonicOscParams;

void fn(double t, double *u, int m, void *udat, double *s_out) {
	DampedHarmonicOscParams *osc = (DampedHarmonicOscParams *) udat;
	//x'' = - omega^2 * x - gamma * v + random(t)
	s_out[0] = u[1];
	s_out[1] = -(osc->omega * osc->omega) * u[0] - osc->gamma * u[1] 
				+ 20 * ((osc->squeeze * sin(osc->omega * t) * gaussrand() 
				+ (1/osc->squeeze) * cos(osc->omega * t) * gaussrand())); //squeezed reservoir
	//s_out[1] = -(osc->omega * osc->omega) * u[0] - osc->gamma * u[1] + 20 * gaussrand(); pure thermal reservoir
}


void dhosc_motion(double omega, double gamma, double squeeze,
	double x_0, double v_0, int nSteps, double finalTime)
{

	DampedHarmonicOscParams osc;
	osc.gamma = gamma;
	osc.omega = omega;
	osc.squeeze = exp(squeeze);
	double t = 0, y[2], ynext[2], ws[10];
	int idx;

	y[0] = x_0; //initial theta coordinate
	y[1] = v_0; //initial v_theta coordinate


	FILE *datafile;
	datafile = fopen("output.dat","w+");

	double tStep = (finalTime/nSteps);
	/* Print in for loop*/
	for (idx = 0; idx < nSteps; idx++)
	{
		stepRK4(t, y, 2, fn, &osc, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		fprintf(datafile, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, y[0], y[1], (omega * omega) * (y[0]*y[0])/2, (y[1]*y[1])/2);
		//fprintf(datafile, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, y[0], y[1], (omega * omega) * (y[0]*cos(omega*t) - y[1]*sin(omega*t)) *(y[0]*cos(omega*t) - y[1]*sin(omega*t))/2, (y[1]*y[1])/2);
	}
}
