/*
 * precedence.c
 * 
 * Operators have precedence rules that determine evaluation order.
 * Use parentheses when in doubt.
 */

#include <stdio.h>

main()
{
    int a = 2, b = 3, c = 4;
    int result;
    
    result = a + b * c;     /* الضرب أولاً: 2 + 12 = 14 */
    printf("%d\n", result);
    
    result = (a + b) * c;   /* الأقواس تغير الترتيب: 5 * 4 = 20 */
    printf("%d\n", result);
    
    /* * / % أعلى من + - */
}
