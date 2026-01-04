/*
 * floating_constants.c
 * 
 * Floating-point constants contain a decimal point or exponent.
 * They are double by default unless marked with f or F.
 */

#include <stdio.h>

main()
{
    double d1, d2, d3;
    float f;
    
    d1 = 123.45;        /* عدد عشري */
    d2 = 1.23e2;        /* صيغة علمية تساوي 123 */
    d3 = .5;            /* يمكن حذف الصفر قبل النقطة */
    f = 3.14f;          /* f في النهاية يعني float */
    
    printf("%f %f %f %f\n", d1, d2, d3, f);
}
