/*
 * non_integer_returns.c
 * 
 * Functions can return any type, not just int.
 * The type must be declared before the function name.
 */

#include <stdio.h>

double square(double x);        /* تصريح بأن الدالة تعيد double */
float average(int a, int b);

main()
{
    double d;
    float f;
    
    d = square(3.5);
    f = average(10, 20);
    
    printf("%f %f\n", d, f);
}

double square(double x)
{
    return x * x;               /* إرجاع double */
}

float average(int a, int b)
{
    return (a + b) / 2.0;       /* إرجاع float */
}
