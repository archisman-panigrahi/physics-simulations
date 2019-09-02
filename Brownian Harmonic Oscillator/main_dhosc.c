#include <stdio.h>
#include <stdlib.h>
#include "dhosc.h"
#include <time.h>	

int main(int argc, char const *argv[])
{
	double omega = 10, gamma = 0.1, squeeze = 0.4;
	double x_0 = 0.1, v_0 = -1;
	int nSteps = 5000;
	double finalTime = 10;
	srand(time(0));
	if(argc > 1){
		x_0 = atof(argv[1]);
	}
	if (argc > 2){
		v_0 = atof(argv[2]);
	}
	if(argc > 3){
		omega = atof(argv[3]);
	}
	if(argc > 4){
		gamma = atof(argv[4]);
	}
	if(argc > 5){
		squeeze = atof(argv[5]);
	}
	if(argc > 6){
		nSteps = atoi(argv[6]);
	}
	if(argc > 7){
		finalTime = atof(argv[7]);
	}

	printf("use dhosc.exe x_0 v_0 omega gamma squeeze nSteps totalTime\n");
	printf("x_0 = %lf\n", x_0);
	printf("v_0 = %lf\n", v_0);
	printf("omega = %lf\n", omega);
	printf("gamma = %lf\n", gamma);
	printf("squeezing parameter = %lf\n", squeeze);
	printf("nSteps = %d\n", nSteps);
	printf("totalTime = %lf\n", finalTime);
	dhosc_motion(omega, gamma, squeeze, x_0, v_0, nSteps, finalTime);
	return 0;
}
