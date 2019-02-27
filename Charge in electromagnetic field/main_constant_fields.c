#include <stdlib.h>
#include <stdio.h>
#include "gsl_const_mksa.h"
#include "print_motion.h"

int main(int argc, char const *argv[]) {

	double no_of_turns = 3;
	double x_0 = 0, y_0 = 0, v_x_0 = 0, v_y_0 = 0;
	int nSteps = 2000;
	double B_0 = 0.002;
	double E_0 = 40;
	double charge = GSL_CONST_MKSA_ELECTRON_CHARGE;
	double mass = GSL_CONST_MKSA_MASS_PROTON;

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

