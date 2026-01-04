/*
 * break_statement.c
 * 
 * Break exits the innermost loop or switch immediately.
 * Control passes to the statement after the loop.
 */

#include <stdio.h>

main()
{
    int i;
    
    for (i = 0; i < 10; i++) {
        if (i == 5)
            break;          /* اخرج من الحلقة فوراً */
        printf("%d\n", i);
    }
    
    printf("after loop\n"); /* التنفيذ يستمر هنا */
}
