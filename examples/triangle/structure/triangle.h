#ifndef _TRIANGLE_INC_
#define _TRIANGLE_INC_

typedef struct _Triangle {
    double a;
    double b;
    double c;
    double A;
    double B;
    double C;
    double area;
} Triangle;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Determines the area and angles of a triangle given its sides.
 *
 * Parameters:
 *             T: Pointer to a Triangle structure
 *
 * Return value: 0 on success,
 *               1 if the sides are such that a triangle is not possible.
 */
int triangleAreaAndAngles(Triangle *T);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_TRIANGLE_INC_) */
