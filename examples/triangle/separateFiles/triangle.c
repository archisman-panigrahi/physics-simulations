#include <math.h>
#include "triangle.h"

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
                          double *A, double *B, double *C, double *area)
{
    double s, prod, aa, bb, cc;
    s = 0.5 * (a + b + c);
    prod = s * (s - a) * (s - b) * (s - c);
    if (prod < 0.0)
        return 1;
    *area = sqrt(prod);
    aa = a * a;
    bb = b * b;
    cc = c * c;
    *A = acos((bb + cc - aa) / (2.0 * b * c));
    *B = acos((cc + aa - bb) / (2.0 * c * a));
    *C = acos((aa + bb - cc) / (2.0 * a * b));
    return 0;
}
