/*
 * implicit_conversions.c
 * 
 * C converts types automatically in some situations.
 * Smaller types convert to larger types in expressions.
 */

#include <stdio.h>

main()
{
    int i = 5;
    float f = 2.5;
    double d;
    
    d = i + f;          /* i يتحول إلى float ثم النتيجة إلى double */
    printf("%f\n", d);
    
    i = f;              /* f يتحول إلى int، الكسر يُحذف */
    printf("%d\n", i);
}
