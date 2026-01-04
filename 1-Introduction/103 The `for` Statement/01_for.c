/*
 * for_structure.c
 * 
 * The for statement is a loop that combines initialization, test, and increment.
 * It is more compact than while when these three parts are present.
 */

#include <stdio.h>

main()
{
    int fahr;
    
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        /* التهيئة؛ الشرط؛ الزيادة */
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }
    
    /* الأجزاء الثلاثة من for مفصولة بفاصلة منقوطة */
}
