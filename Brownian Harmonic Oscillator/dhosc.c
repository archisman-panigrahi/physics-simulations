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
				+ 1000 * ((osc->squeeze * sin(osc->omega * t) * gaussrand() 
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
	double x, v;

	FILE *datafile;
	datafile = fopen("output.csv","w+");
	fprintf(datafile, "r,%lf\n", squeeze);
	double tStep = (finalTime/nSteps);

	double Energy_rot_1 = 0;
	double Energy_rot_2 = 0;

	double Energy_1 = 0;
	double Energy_2 = 0;
	/* Print in for loop*/
	for (idx = 0; idx < nSteps; idx++)
	{
		stepRK4(t, y, 2, fn, &osc, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		x = (y[0] * sqrt(omega));
		v = (y[1] / sqrt(omega));

		Energy_rot_1 += (omega * ( (x * cos(omega*t)) - (v * sin(omega*t)) ) * ( (x * cos(omega*t)) - (v * sin(omega*t)) )/2)/nSteps;
		Energy_rot_2 += (omega * ( (v * cos(omega*t)) + (x * sin(omega*t)) ) * ( (v * cos(omega*t)) + (x * sin(omega*t)) )/2)/nSteps;

		Energy_1 += omega * x * x/nSteps;
		Energy_2 += omega * v * v/nSteps;
		//fprintf(datafile, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, y[0], y[1], (omega * omega) * (y[0]*y[0])/2, (y[1]*y[1])/2);
		fprintf(datafile, "%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", t, y[0], y[1],
			omega * ( (x * cos(omega*t)) - (v * sin(omega*t)) ) * ( (x * cos(omega*t)) - (v * sin(omega*t)) )/2, //rotating_energy_1
		    omega * ( (v * cos(omega*t)) + (x * sin(omega*t)) ) * ( (v * cos(omega*t)) + (x * sin(omega*t)) )/2, //rotating_energy_2
		    omega * x * x, //Energy in position
		    omega * v * v); //Energy in velocity
	}
	
	FILE *details;
	details = fopen("details.csv", "w+");
	fprintf(details, "r, %lf\n", squeeze);
	fprintf(details,"Energy in first rotating quadrature, %lf\n", Energy_rot_1);
	fprintf(details,"Energy in second rotating quadrature, %lf\n", Energy_rot_2);
	fprintf(details,"Total Energy, %lf\n", (Energy_rot_1 + Energy_rot_2));
	fprintf(details,"Experimental ratio, %lf\n", (Energy_rot_1/Energy_rot_2));
	fprintf(details,"Ratio predicted by me, %lf\n", (2*cosh(2*squeeze) + sinh(2*squeeze))/(2*cosh(2*squeeze) - sinh(2*squeeze)));
	fprintf(details,"Ratio predicted by paper, %lf\n", exp(4*squeeze));
	fprintf(details,"Energy in position, %lf\n", Energy_1);
	fprintf(details,"Energy in momentum, %lf\n", Energy_2);
}