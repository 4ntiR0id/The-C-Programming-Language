/*
 * for_loop.c
 * 
 * The for loop is convenient when counting.
 * It combines initialization, test, and increment.
 */

#include <stdio.h>

main()
{
    int i;
    
    for (i = 0; i < 5; i++) {   /* التهيئة؛ الشرط؛ الزيادة */
        printf("%d\n", i);
    }
    
    /* يعادل:
       i = 0;
       while (i < 5) {
           printf("%d\n", i);
           i++;
       }
    */
}
