#ifndef _PRINT_MOTION_INC_
#define _PRINT_MOTION_INC_

#ifdef __cplusplus
extern "C" {
#endif

void print_motion(double E_0, double B_0, double charge, double mass,
	double no_of_turns, double x_0, double y_0, double v_x_0, double v_y_0, int nSteps);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_PRINT_MOTION_INC_) */
