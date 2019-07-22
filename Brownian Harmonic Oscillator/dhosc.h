#ifndef _DHOSC_INC_
#define _DHOSC_INC_

#ifdef __cplusplus
extern "C" {
#endif

void dhosc_motion(double omega, double gamma, double squeeze,
	double x_0, double v_0, int nSteps, double finalTime);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_DHOSC_INC_) */
