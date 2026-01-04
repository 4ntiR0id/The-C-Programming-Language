/*
 * for_vs_while.c
 * 
 * The for and while loops can express the same computation.
 * Choose for when initialization and increment are simple and related.
 */

#include <stdio.h>

main()
{
    int i;
    
    /* نفس الحلقة باستخدام while */
    i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i = i + 1;
    }
    
    printf("\n");
    
    /* نفس الحلقة باستخدام for */
    for (i = 0; i < 10; i = i + 1)
        printf("%d\n", i);
    
    /* for أوضح عندما تكون الأجزاء الثلاثة بسيطة */
}
