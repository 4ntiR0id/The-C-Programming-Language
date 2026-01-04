/*
 * while_loop.c
 * 
 * The while loop repeats as long as the condition is true.
 * The test happens before each iteration.
 */

#include <stdio.h>

main()
{
    int i = 0;
    
    while (i < 5) {         /* اختبر الشرط أولاً */
        printf("%d\n", i);
        i++;                /* زد i */
    }                       /* ارجع للاختبار مرة أخرى */
    
    /* إذا كان الشرط خاطئاً من البداية، لا تنفذ الحلقة أبداً */
}
