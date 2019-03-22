#include <stdlib.h>
#include <stdio.h>
#include "gsl_const_mksa.h"
#include "print_motion.h"

int main(int argc, char const *argv[]) {

	double no_of_turns = 3;
	double x_0 = 0, y_0 = 0, v_x_0 = 0, v_y_0 = 0;
	int nSteps = 500;
	double B_0 = 0.002;
	double E_0 = 40;
	double charge = GSL_CONST_MKSA_ELECTRON_CHARGE;
	double mass = GSL_CONST_MKSA_MASS_PROTON;
	char *epTxt;
	/*get input using environment variables*/
	epTxt = getenv("E_0");	
	if (epTxt != NULL)
		E_0 = atof(epTxt);
	epTxt = getenv("B_0");
	if (epTxt != NULL)
		B_0 = atof(epTxt);
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

	/*Alternatively, usr argc*/
	if(argc > 1){
		B_0 = atof(argv[1]);
	}
	if (argc > 2){
		E_0 = atof(argv[2]);
	}
	if(argc > 3){
		x_0 = atof(argv[3]);
	}
	if(argc > 4){
		y_0 = atof(argv[4]);
	}
	if(argc > 5){
		v_x_0 = atof(argv[5]);
	}
	if(argc > 6){
		v_y_0 = atof(argv[6]);
	}
	if (argc > 7){
		nSteps = atof(argv[7]);
	}
	if (argc > 8){
		no_of_turns = atof(argv[8]);
	}
	if (argc > 9){
		charge = atof(argv[9]);
	}
	if (argc > 10){
		mass = atof(argv[10]);
	}

	print_motion(E_0, B_0, charge, mass, no_of_turns, x_0, y_0, v_x_0, v_y_0, nSteps);
	return 0;
}

