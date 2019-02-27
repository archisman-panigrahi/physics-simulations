#include <stdio.h>
#include <math.h>
#include "magnetron.h"
#include "ode.h"

typedef struct _MagnetronParams {
	double V_0;
	double B_0;
	double charge;
	double mass;
	double a;
	double b;
	double ChargeOverMass;
	double VzeroOverLog;
} MagnetronParams;

void fn(double t, double *u, int m, void *udat, double *s_out) {
	MagnetronParams *mt = (MagnetronParams *) udat;
	s_out[0] = u[2];
	s_out[1] = u[3];
	s_out[2] = (mt->ChargeOverMass) * ((mt->VzeroOverLog * u[0] / (u[0]*u[0] + u[1]*u[1])) + (mt->B_0 * u[3]));
	s_out[3] = (mt->ChargeOverMass) * ((mt->VzeroOverLog * u[1] / (u[0]*u[0] + u[1]*u[1])) - (mt->B_0 * u[2]));
}


void magnetron_motion(double V_0, double B_0, double charge, double mass,
	double a, double b, double no_of_turns, double x_0, double y_0, double v_x_0, double v_y_0, int nSteps)
{

	MagnetronParams mt;
	mt.V_0 = V_0;
	mt.B_0 = B_0;
	mt.charge = charge;
	mt.mass = mass;
	mt.a = a;
	mt.b = b;
	mt.ChargeOverMass = charge/mass;
	printf("ChargeOverMass = %lf\n", mt.ChargeOverMass);
	mt.VzeroOverLog = V_0/(log(b/a)); //base e

	double t = 0, y[4], ynext[4], ws[10];
	int idx;

	y[0] = x_0; //initial x coordinate
	y[1] = y_0; //initial y coordinate
	y[2] = v_x_0; //initial v_x
	y[3] = v_y_0; //initial v_y

	FILE *datafile;
	datafile = fopen("magnetron.dat","w+");

	double tStep = fabs(no_of_turns * (2 * M_PI) /((mt.ChargeOverMass * mt.B_0) * nSteps));

	/* Print in for loop*/
	for (idx = 0; idx < nSteps; idx ++)
	{
		stepRK4(t, y, 4, fn, &mt, ws, tStep, ynext);
		t += tStep;
		y[0] = ynext[0];
		y[1] = ynext[1];
		y[2] = ynext[2];
		y[3] = ynext[3];
		if(hypot(y[0],y[1]) > b)
		{	printf("Touched Outer Wall\n");
			break;
		}
		else if (hypot(y[0],y[1]) < a)
		{
			printf("Touched Inner Wall\n");
			break;
		}
		fprintf(datafile, "%lf\t%lf\t%lf\n", t, y[0], y[1]);
	}
}