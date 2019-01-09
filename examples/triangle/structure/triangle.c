#include <math.h>
#include "triangle.h"

/**
 * Determines the area and angles of a triangle given its sides.
 *
 * Parameters:
 *             T: Pointer to a Triangle structure
 *
 * Return value: 0 on success,
 *               1 if the sides are such that a triangle is not possible.
 */
int triangleAreaAndAngles(Triangle *T)
{
    double s, prod, aa, bb, cc;
    s = 0.5 * (T->a + T->b + T->c);
    prod = s * (s - T->a) * (s - T->b) * (s - T->c);
    if (prod < 0.0)
        return 1;
    T->area = sqrt(prod);
    aa = T->a * T->a;
    bb = T->b * T->b;
    cc = T->c * T->c;
    T->A = acos((bb + cc - aa) / (2.0 * T->b * T->c));
    T->B = acos((cc + aa - bb) / (2.0 * T->c * T->a));
    T->C = acos((aa + bb - cc) / (2.0 * T->a * T->b));
    return 0;
}
