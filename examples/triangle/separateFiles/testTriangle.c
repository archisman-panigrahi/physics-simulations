#include <stdlib.h>
#include <stdio.h>
#include "triangle.h"

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
