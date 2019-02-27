#include <stdio.h>
#include <stdlib.h>
#include "magnetron.h"
#include "gsl_const_mksa.h"

int main(int argc, char const *argv[])
{
	double V_0 = 24000, B_0 = 0.02, charge = GSL_CONST_MKSA_ELECTRON_CHARGE, 
	mass = GSL_CONST_MKSA_MASS_ELECTRON, a = 0.01, b = 0.03, no_of_turns = 40,
	x_0 = 0.01732050808, y_0 = 0, v_x_0 = 0, v_y_0 = 0;
	int nSteps = 5000;

	if(argc > 1){
		V_0 = atof(argv[1]);
	}
	if (argc > 2){
		B_0 = atof(argv[2]);
	}
	if(argc > 3){
		a = atof(argv[3]);
	}
	if(argc > 4){
		b = atof(argv[4]);
	}
	if(argc > 5){
		x_0 = atof(argv[5]);
	}
	if(argc > 6){
		y_0 = atof(argv[6]);
	}
	if (argc > 7){

		v_x_0 = atof(argv[7]);
	}
	if (argc > 8){
		v_y_0 = atof(argv[8]);
	}
	if (argc > 9){
		nSteps = atoi(argv[9]);
	}
	if (argc > 10){
		no_of_turns = atof(argv[10]);
	}
	if (argc > 11){
		charge = atof(argv[11]);
	}
	if (argc > 12){
		mass = atof(argv[12]);
	}
	printf("V_0 = %lf\n", V_0);
	printf("B_0 = %lf\n", B_0);
	printf("a = %lf\n", a);
	printf("b = %lf\n", b);
	printf("x_0 = %lf\n", x_0);
	printf("y_0 = %lf\n", y_0);
	printf("v_x_0 = %lf\n", v_x_0);
	printf("v_y_0 = %lf\n", v_y_0);
	printf("nSteps = %d\n", nSteps);
	printf("no_of_turns = %lf\n", no_of_turns);
	printf("charge = %lf\n", charge);
	printf("mass = %lf\n", mass);
	magnetron_motion(V_0, B_0, charge, mass, a, b, no_of_turns, x_0, y_0, v_x_0, v_y_0, nSteps);

	return 0;
}