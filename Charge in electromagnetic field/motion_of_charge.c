//To do - calculate exact coordinates
// for non-zero initial position and velocities
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gsl_const_mksa.h"
#include "ode.h"

typedef struct _CyclParams {
	double B_0;
	double E_0;
	double charge;
	double mass;
	double omega;
	double vdrift;
} CyclParams;

void fn(double t, double *u, int m, void *udat, double *s_out) {
	CyclParams *cy = (CyclParams *) udat;
	s_out[0] = u[2];
	s_out[1] = u[3];
	s_out[2] = (cy->omega) * u[3];
	s_out[3] = (cy->omega) * (cy->vdrift - u[2]);
}

int main(int argc, char const *argv[])
{
	CyclParams cy;
	cy.B_0 = 0.002;
	cy.E_0 = 40;
	cy.charge = GSL_CONST_MKSA_ELECTRON_CHARGE;
	cy.mass = GSL_CONST_MKSA_MASS_PROTON;
	
	int no_of_turns = 3;

	double t, y[4], ynext[4], ws[10], yexact[2];
	int idx, nSteps = 2000;



	y[0] = 0; //initial x coordinate
	y[1] = 0; //initial y coordinate
	y[2] = 0; //initial v_x
	y[3] = 0; //initial v_y


	if(argc > 1){
		cy.B_0 = atof(argv[1]);
	}
	if (argc > 2){
		cy.E_0 = atof(argv[2]);
	}
	if(argc > 3){
		y[0] = atof(argv[3]);
	}
	if(argc > 4){
		y[1] = atof(argv[4]);
	}
	if(argc > 5){
		y[2] = atof(argv[5]);
	}
	if(argc > 6){
		y[3] = atof(argv[6]);
	}
	if (argc > 7){
		nSteps = atof(argv[7]);
	}
	if (argc > 8){
		no_of_turns = atoi(argv[8]);
	}
	if (argc > 9){
		cy.charge = atof(argv[9]);
	}
	if (argc > 10){
		cy.mass = atof(argv[10]);
	}
	cy.omega = fabs((cy.charge * cy.B_0)/cy.mass);
	cy.vdrift = (cy.E_0)/(cy.B_0);

	printf("omega = %lf\n", cy.omega);
	printf("drift velocity = %lf\n", cy.vdrift);
	printf("radius = %lf\n", fabs(cy.mass * cy.vdrift/(cy.charge * cy.B_0)));
	FILE *datafile;
	datafile=fopen("output.dat","w+");

	double tStep = no_of_turns * 2 * (M_PI/cy.omega)/ nSteps;


	for (idx = 0; idx < nSteps; idx ++)
	{
		stepRK4(t, y, 4, fn, &cy, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		y[2] = ynext[2];
		y[3] = ynext[3];

		yexact[0] = (cy.vdrift/cy.omega) * ((cy.omega * t) - sin(cy.omega * t));
		yexact[1] = (cy.vdrift/cy.omega) * (1 - cos(cy.omega * t));
		fprintf(datafile, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, y[0], y[1], yexact[0], yexact[1]);
	}
	return 0;
}