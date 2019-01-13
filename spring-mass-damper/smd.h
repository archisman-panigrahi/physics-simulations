#ifndef _smd_h
#define _smd_h
//This function takes x_0, v_0, m, b, k, t_f, iterations, and 
//address of x and v, and print_to_file (0 will only change values, 1 will print)
//as input and changes the values at x and v
//it returns 1 if anything is wrong otherwise returns 0
int smd(long double, long double, long double, long double, long double, long double, long double, long double *, long double *, int);

#endif