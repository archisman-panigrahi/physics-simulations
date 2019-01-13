#include <stdio.h>
#include <math.h>
void main()
{
	long double t,x,i,x_0,v,v_0,a,k,m,b,t_f,delta_t,iterations;
	printf("Input initial value of x:	");
	scanf("%Lf", &x_0);
	printf("Input initial value of v:	");
	scanf("%Lf", &v_0);
	printf("Input spring constant:	");
	scanf("%Lf", &k);
	printf("Input damping constant:	");
	scanf("%Lf", &b);
	printf("Input mass:	");
	scanf("%Lf", &m);
	printf("Enter value of t to calculate x for:	");
	scanf("%Lf", &t_f);
	printf("Enter no of iterations:	");
	scanf("%Lf", &iterations);
	x = x_0;
	v = v_0;
	t = 0;
	delta_t = t_f/iterations;
	if(m != 0)
	{
		k = k/m;
		b = b/m;
	}
	else
	{
		for (i = 0; i < iterations; i++)
		{
			t = t + delta_t;
			x = x - ((k/b) * x * delta_t);
			printf("%Lf \t %Lf \t %Lf\n", i,t,x); //step	t    x
		}
		printf("x is %Lf at t = %Lf\n", x, t_f);
		return;
	}

	for (i = 0; i < iterations; i++)
	{
		t = t + delta_t;
		a = -((b * v) + (k * x));
		x = x + (v * delta_t) + ((a * delta_t * delta_t)/2);
		v = v + (a * delta_t) - (((b * a) + (k * v)) * (delta_t * delta_t)/2);
		printf("%Lf \t %Lf \t %Lf\n", i,t,x); //step	t    x
	}
	printf("x is %Lf at t = %Lf\n", x, t_f);
}