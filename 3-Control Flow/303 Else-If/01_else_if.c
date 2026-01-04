/*
 * else_if.c
 * 
 * Else-if chains test multiple conditions in sequence.
 * Only the first true condition is executed.
 */

#include <stdio.h>

main()
{
    int score = 75;
    
    if (score >= 90)            /* اختبر الأول */
        printf("A\n");
    else if (score >= 80)       /* إذا فشل، اختبر الثاني */
        printf("B\n");
    else if (score >= 70)       /* وهكذا */
        printf("C\n");
    else if (score >= 60)
        printf("D\n");
    else                        /* إذا فشلت كل الشروط */
        printf("F\n");
}
