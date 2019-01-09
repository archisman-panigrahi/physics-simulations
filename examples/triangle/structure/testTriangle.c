#include <stdlib.h>
#include <stdio.h>
#include "triangle.h"

int main(int argc, char *argv[])
{
    Triangle T;
    int rv;

    T.a = 4.0;
    T.b = 5.0;
    T.c = 6.0;
    if (argc > 1)
        T.a = atof(argv[1]);
    if (argc > 2)
        T.b = atof(argv[2]);
    if (argc > 3)
        T.c = atof(argv[3]);

    rv = triangleAreaAndAngles(&T);
    if (rv) {
        printf("Triangle not possible.\n");
    } else {
        printf("area = %g\n", T.area);
        printf("A = %g, B = %g, C = %g\n", T.A, T.B, T.C);
    }
    return 0;
}
