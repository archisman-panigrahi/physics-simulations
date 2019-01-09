#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int triangleAreaAndAngles(double a, double b, double c,
                          double *A, double *B, double *C, double *area)
{
    double s, prod;
    s = 0.5 * (a + b + c);
    prod = s * (s - a) * (s - b) * (s - c);
    if (prod < 0.0)
        return 1;
    *area = sqrt(prod);
    *A = acos((b * b + c * c - a * a) / (2.0 * b * c));
    *B = acos((c * c + a * a - b * b) / (2.0 * c * a));
    *C = acos((a * a + b * b - c * c) / (2.0 * a * b));
    return 0;
}

int main(int argc, char *argv[])
{
    double a = 4.0, b = 5.0, c = 6.0;
    double area, A, B, C;
    int rv;

    if (argc > 1)
        a = atof(argv[1]);
    if (argc > 2)
        b = atof(argv[2]);
    if (argc > 3)
        c = atof(argv[3]);

    rv = triangleAreaAndAngles(a, b, c, &A, &B, &C, &area);
    if (rv) {
        printf("Triangle not possible.\n");
    } else {
        printf("area = %g\n", area);
        printf("A = %g, B = %g, C = %g\n", A, B, C);
    }
    return 0;
}
