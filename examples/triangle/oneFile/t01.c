#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double a = 4.0, b = 5.0, c = 6.0;
    double s, prod, area, A, B, C;

    if (argc > 1)
        a = atof(argv[1]);
    if (argc > 2)
        b = atof(argv[2]);
    if (argc > 3)
        c = atof(argv[3]);

    s = 0.5 * (a + b + c);
    prod = s * (s - a) * (s - b) * (s - c);
    if (prod > 0.0) {
        area = sqrt(prod);
        A = acos((b * b + c * c - a * a) / (2.0 * b * c));
        B = acos((c * c + a * a - b * b) / (2.0 * c * a));
        C = acos((a * a + b * b - c * c) / (2.0 * a * b));
        printf("area = %g\n", area);
        printf("A = %g, B = %g, C = %g\n", A, B, C);
    } else {
        printf("Triangle not possible.\n");
    }
    return 0;
}
