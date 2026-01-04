/*
 * explicit_casting.c
 * 
 * A cast forces a value to a specific type.
 * Use it to control conversions precisely.
 */

#include <stdio.h>

main()
{
    int a = 5, b = 2;
    float result;
    
    result = a / b;             /* قسمة صحيحة: 2.0 */
    printf("%f\n", result);
    
    result = (float) a / b;     /* تحويل صريح: 2.5 */
    printf("%f\n", result);
    
    /* (float) يجبر a على أن يصبح float */
}
