/*
 * goto_statement.c
 * 
 * Goto transfers control to a labeled statement.
 * Use it sparingly, usually for error handling.
 */

#include <stdio.h>

main()
{
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                goto done;      /* اذهب إلى التسمية done */
            printf("%d %d\n", i, j);
        }
    }
    
done:                           /* التسمية */
    printf("finished\n");
    
    /* goto مفيد للخروج من حلقات متداخلة */
}
