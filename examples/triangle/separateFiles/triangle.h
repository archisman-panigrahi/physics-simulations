#ifndef _TRIANGLE_INC_
#define _TRIANGLE_INC_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Determines the area and angles of a triangle given its sides.
 *
 * Input parameters:
 *                   a, b, c : Sides of the triangle
 *
 * Output parameters:
 *                   A, B, C: Pointers to the angles
 *                      area: Pointer to the area
 *
 * Return value: 0 on success,
 *               1 if the sides are such that a triangle is not possible.
 */
int triangleAreaAndAngles(double a, double b, double c,
                          double *A, double *B, double *C, double *area);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_TRIANGLE_INC_) */
