#include <math.h>
//#include <stdio.h>

int smd(long double x_0, long double v_0, long double m, long double b, long double k,
		long double t_f, long double iterations, long double *x, long double *v, int print_to_file)
{
	long double delta_t = (t_f/iterations);
	long double a,i;
	(*x) = x_0;
	(*v) = v_0;
	if (m == 0 && b == 0)
		return 1;
	else if(m == 0)
	{
		for (i = 0; i < iterations; i++)
		{
			(*x) = (*x) - ((k/b) * (*x) * delta_t) + ((k/b) * (k/b) * (*x) * delta_t * delta_t/2);
			//printf("%Lf \t %Lf\n", i, *x);
		}
		(*v) = (-k/b) * (*x);
		return 0;
	}
	else
	{
		long double k_prime = k/m;
		long double b_prime = b/m;
		for (i = 0; i < iterations; i++)
		{
			a = -((b_prime * (*v)) + (k_prime * (*x)));
			(*x) = (*x) + ((*v) * delta_t) + ((a * delta_t * delta_t)/2);
			(*v) = (*v) + (a * delta_t) - (((b_prime * a) + (k_prime * (*v))) * (delta_t * delta_t)/2);
			//printf("%Lf \t %Lf\n", i, *x);
		}
		return 0;
	}
}