/*
 * arithmetic_operators.c
 * 
 * The basic arithmetic operators work on numbers.
 * Integer division discards the remainder.
 */

#include <stdio.h>

main()
{
    int a = 10, b = 3;
    
    printf("%d\n", a + b);  /* جمع: 13 */
    printf("%d\n", a - b);  /* طرح: 7 */
    printf("%d\n", a * b);  /* ضرب: 30 */
    printf("%d\n", a / b);  /* قسمة: 3 */
    printf("%d\n", a % b);  /* باقي القسمة: 1 */
    
    /* % يعمل فقط مع الأعداد الصحيحة */
}
