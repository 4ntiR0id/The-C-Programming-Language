/*
 * data_type_double.c
 * 
 * A double holds a floating-point number with more precision.
 * Use it when float is not accurate enough.
 */

#include <stdio.h>

main()
{
    double pi;
    double large_number;
    
    pi = 3.14159265358979;  /* دقة أكبر من float */
    large_number = 1.23e10; /* يمكن استخدام الصيغة العلمية */
    
    printf("%.15f\n", pi);
    printf("%e\n", large_number);   /* %e للصيغة العلمية */
}
