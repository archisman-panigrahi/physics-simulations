#include <stdio.h>
#include <stdlib.h>
#include "magnetron.h"
#include "gsl_const_mksa.h"

int main(int argc, char const *argv[])
{
	double V_0 = -2400, B_0 = 0.015, charge = -GSL_CONST_MKSA_ELECTRON_CHARGE, 
	mass = GSL_CONST_MKSA_MASS_ELECTRON, a = 0.01, b = 0.03, no_of_turns = 20,
	x_0 = 0.01732050808, y_0 = 0, v_x_0 = 0, v_y_0 = 0;
	int nSteps = 2000;
	char *epTxt;
	/*get input using environment variables*/
	epTxt = getenv("V_0");	
	if (epTxt != NULL)
		V_0 = atof(epTxt);
	epTxt = getenv("B_0");
	if (epTxt != NULL)
		B_0 = atof(epTxt);
	epTxt = getenv("a");
	if (epTxt != NULL)
		a = atof(epTxt);
	epTxt = getenv("b");
	if (epTxt != NULL)
		b = atof(epTxt);
	epTxt = getenv("x_0");
	if (epTxt != NULL)
		x_0 = atof(epTxt);
	epTxt = getenv("y_0");
	if (epTxt != NULL)
		y_0 = atof(epTxt);
	epTxt = getenv("v_x_0");
	if (epTxt != NULL)
		v_x_0 = atof(epTxt);
	epTxt = getenv("v_y_0");
	if (epTxt != NULL)
		v_y_0 = atof(epTxt);
	epTxt = getenv("nSteps");
	if (epTxt != NULL)
		nSteps = atoi(epTxt);
	epTxt = getenv("turns");
	if (epTxt != NULL)
		no_of_turns = atof(epTxt);
	epTxt = getenv("charge");
	if (epTxt != NULL)
		charge = atof(epTxt);
	epTxt = getenv("mass");
	if (epTxt != NULL)
		mass = atof(epTxt);

	/*Alternatively, get input using argv*/
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
	printf("charge = %e\n", charge);
	printf("mass = %e\n", mass);
	magnetron_motion(V_0, B_0, charge, mass, a, b, no_of_turns, x_0, y_0, v_x_0, v_y_0, nSteps);

	return 0;
}