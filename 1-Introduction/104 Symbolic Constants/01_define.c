/*
 * symbolic_constants.c
 * 
 * A symbolic constant is a name that stands for a particular value.
 * Using names instead of numbers makes programs easier to read and change.
 */

#include <stdio.h>

#define LOWER 0      /* الحد الأدنى للجدول */
#define UPPER 300    /* الحد الأعلى */
#define STEP  20     /* حجم الخطوة */

main()
{
    int fahr;
    
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    
    /* لا توجد فاصلة منقوطة بعد #define */
    /* الثوابت تكتب عادة بأحرف كبيرة */
}
