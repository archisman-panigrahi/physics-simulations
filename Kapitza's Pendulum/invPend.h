#ifndef _INV_PEND_INC_
#define _INV_PEND_INC_

#ifdef __cplusplus
extern "C" {
#endif

void InvPend_motion(double l, double g, double a, double omega,
	double theta_0, double v_theta_0, int nSteps, double finalTime);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_INV_PEND_INC_) */
