#ifndef _MAGNETRON_INC_
#define _MAGNETRON_INC_

#ifdef __cplusplus
extern "C" {
#endif

void magnetron_motion(double V_0, double B_0, double charge, double mass,
	double a, double b, double no_of_turns, double x_0, double y_0, double v_x_0, double v_y_0, int nSteps);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_MAGNETRON_INC_) */
