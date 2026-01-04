/*
 * if_else.c
 * 
 * The if statement executes code conditionally.
 * The else part is optional.
 */

#include <stdio.h>

main()
{
    int x = 10;
    
    if (x > 5)              /* إذا كان الشرط صحيحاً */
        printf("x is greater than 5\n");
    
    if (x > 20)
        printf("x is greater than 20\n");
    else                    /* وإلا */
        printf("x is not greater than 20\n");
}
