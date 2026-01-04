/*
 * compound_assignment.c
 * 
 * Compound assignments combine an operation with assignment.
 * They make code shorter and clearer.
 */

#include <stdio.h>

main()
{
    int x = 10;
    
    x += 5;             /* يعادل: x = x + 5 */
    printf("%d\n", x);
    
    x -= 3;             /* يعادل: x = x - 3 */
    printf("%d\n", x);
    
    x *= 2;             /* يعادل: x = x * 2 */
    printf("%d\n", x);
    
    x /= 4;             /* يعادل: x = x / 4 */
    printf("%d\n", x);
    
    /* يوجد أيضاً: %=, &=, |=, ^=, <<=, >>= */
}
