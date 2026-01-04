/*
 * mathematical_functions.c
 * 
 * Mathematical functions perform common calculations.
 * They are declared in math.h.
 */

#include <stdio.h>
#include <math.h>

main()
{
    double x, result;
    
    x = 2.0;
    
    /* قوى وجذور */
    result = sqrt(x);               /* جذر تربيعي */
    result = pow(x, 3.0);           /* أس: x^3 */
    result = exp(x);                /* e^x */
    result = log(x);                /* لوغاريتم طبيعي */
    result = log10(x);              /* لوغاريتم عشري */
    
    /* مثلثية */
    result = sin(x);                /* جيب */
    result = cos(x);                /* جيب تمام */
    result = tan(x);                /* ظل */
    result = asin(x);               /* معكوس الجيب */
    
    /* أخرى */
    result = fabs(x);               /* قيمة مطلقة */
    result = ceil(x);               /* تقريب لأعلى */
    result = floor(x);              /* تقريب لأسفل */
}
