/*
 * continue_statement.c
 * 
 * Continue skips to the next iteration of the loop.
 * It does not exit the loop, only the current iteration.
 */

#include <stdio.h>

main()
{
    int i;
    
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0)
            continue;       /* تخطى بقية الحلقة وانتقل للتكرار التالي */
        printf("%d\n", i);  /* يطبع الأعداد الفردية فقط */
    }
}
