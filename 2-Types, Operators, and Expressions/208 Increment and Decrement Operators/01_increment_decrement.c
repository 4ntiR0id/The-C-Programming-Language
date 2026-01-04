/*
 * increment_decrement.c
 * 
 * ++ adds 1, -- subtracts 1.
 * They can be prefix or postfix, which affects timing.
 */

#include <stdio.h>

main()
{
    int x = 5, y;
    
    y = x++;            /* y يأخذ القيمة القديمة 5، ثم x يصبح 6 */
    printf("%d %d\n", x, y);
    
    x = 5;
    y = ++x;            /* x يصبح 6 أولاً، ثم y يأخذ 6 */
    printf("%d %d\n", x, y);
    
    /* نفس الشيء مع -- */
}
