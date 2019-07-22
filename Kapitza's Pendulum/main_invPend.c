#include <stdio.h>
#include <stdlib.h>
#include "invPend.h"

int main(int argc, char const *argv[])
{
	double g = 9.80665, l = 1, a = 0.1, omega = 100;
	double theta_0 = 0.1, v_theta_0 = -1;
	int nSteps = 5000;
	double finalTime = 10;
	char *epTxt;
	/*get input using environment variables*/
	epTxt = getenv("g");	
	if (epTxt != NULL)
		g = atof(epTxt);
	epTxt = getenv("l");
	if (epTxt != NULL)
		l = atof(epTxt);
	epTxt = getenv("a");
	if (epTxt != NULL)
		a = atof(epTxt);
	epTxt = getenv("omega");
	if (epTxt != NULL)
		omega = atof(epTxt);
	epTxt = getenv("theta_0");
	if (epTxt != NULL)
		theta_0 = atof(epTxt);
	epTxt = getenv("v_theta_0");
	if (epTxt != NULL)
		v_theta_0 = atof(epTxt);
	epTxt = getenv("nSteps");
	if (epTxt != NULL)
		nSteps = atoi(epTxt);
	epTxt = getenv("time");
	if (epTxt != NULL)
		finalTime = atof(epTxt);


	/*Alternatively, get input using argv*/
	if(argc > 1){
		theta_0 = atof(argv[1]);
	}
	if (argc > 2){
		v_theta_0 = atof(argv[2]);
	}
	if(argc > 3){
		omega = atof(argv[3]);
	}
	if(argc > 4){
		nSteps = atoi(argv[4]);
	}
	if(argc > 5){
		finalTime = atof(argv[5]);
	}
	if(argc > 6){
		a = atof(argv[6]);
	}
	if(argc > 7){
		g = atof(argv[7]);
	}
	if(argc > 8)
	{
		l = atof(argv[8]);
	}
	printf("use inverted_pendulum_motion.exe theta_0 v_theta_0 omega nSteps totalTime a g l\n");
	printf("g = %lf\n", g);
	printf("l = %lf\n", l);
	printf("a = %lf\n", a);
	printf("omega = %lf\n", omega);
	printf("theta_0 = %lf\n", theta_0);
	printf("v_theta_0 = %lf\n", v_theta_0);
	printf("nSteps = %d\n", nSteps);
	printf("totalTime = %lf\n", finalTime);

	InvPend_motion(l, g, a, omega, theta_0, v_theta_0, nSteps, finalTime);

	return 0;
}