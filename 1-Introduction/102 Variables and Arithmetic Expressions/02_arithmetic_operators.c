/*
 * arithmetic_operators.c
 * 
 * C provides the basic arithmetic operations.
 * Integer division truncates any fractional part.
 */

#include <stdio.h>

main()
{
    int a, b;
    
    a = 10;
    b = 3;
    
    printf("%d\n", a + b);  /* الجمع */
    printf("%d\n", a - b);  /* الطرح */
    printf("%d\n", a * b);  /* الضرب */
    printf("%d\n", a / b);  /* القسمة تعطي 3 وليس 3.33 */
    printf("%d\n", a % b);  /* الباقي من القسمة */
}
