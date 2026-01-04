/*
 * order_of_evaluation.c
 * 
 * C does not specify evaluation order for most operators.
 * Avoid expressions where order matters.
 */

#include <stdio.h>

main()
{
    int x = 5;
    int y;
    
    y = x + x++;        /* ترتيب التنفيذ غير محدد */
    /* هل x++ قبل أم بعد القراءة؟ */
    
    /* الأفضل: */
    x = 5;
    y = x + x;
    x++;
    
    printf("%d\n", y);
}
