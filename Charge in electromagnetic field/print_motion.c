#include <stdio.h>
#include <math.h>
#include "print_motion.h"
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


void print_motion(double E_0, double B_0, double charge, double mass,
	double no_of_turns, double x_0, double y_0, double v_x_0, double v_y_0, int nSteps)
{

	CyclParams cy;
	cy.E_0 = E_0;
	cy.B_0 = B_0;
	cy.charge = charge;
	cy.mass = mass;
	cy.omega = (cy.charge * cy.B_0)/cy.mass;
	cy.vdrift = (cy.E_0)/(cy.B_0);

	double t, y[4], ynext[4], ws[10], yexact[2];
	int idx;

	y[0] = x_0; //initial x coordinate
	y[1] = y_0; //initial y coordinate
	y[2] = v_x_0; //initial v_x
	y[3] = v_y_0; //initial v_y

	printf("omega = %lf\n", cy.omega);
	printf("drift velocity = %lf\n", cy.vdrift);
	printf("radius = %lf\n", fabs((cy.mass * cy.vdrift)/(cy.charge * cy.B_0)));
	FILE *datafile;
	datafile=fopen("output.dat","w+");

	double tStep = fabs(no_of_turns * 2 * (M_PI/cy.omega)/ nSteps);
	
	/* Quantities required for exact coordinates*/
	double v_0 = hypot((v_x_0 - cy.vdrift),v_y_0);
	double phi_0 = atan2(v_y_0, (v_x_0 - cy.vdrift));

	/* Print in for loop*/
	for (idx = 0; idx < nSteps; idx ++)
	{
		stepRK4(t, y, 4, fn, &cy, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		y[2] = ynext[2];
		y[3] = ynext[3];

		yexact[0] = x_0 + (cy.vdrift * t) + (v_0/cy.omega) * (sin(cy.omega * t - phi_0) + sin(phi_0));
		yexact[1] = y_0 + (v_0/cy.omega) * (cos(cy.omega * t - phi_0) - cos(phi_0));
		fprintf(datafile, "%lf\t%lf\t%lf\t%lf\t%lf\n", t, y[0], y[1], yexact[0], yexact[1]);
	}
}