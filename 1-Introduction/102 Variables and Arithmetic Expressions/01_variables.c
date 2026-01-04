/*
 * variables.c
 * 
 * Variables hold values that can change during program execution.
 * Every variable must be declared before use.
 */

#include <stdio.h>

main()
{
    int fahr, celsius;  /* أعداد صحيحة */
    int lower, upper, step;  /* يمكن تعريف عدة متغيرات في سطر واحد */
    
    lower = 0;  /* الحد الأدنى */
    upper = 300;  /* الحد الأعلى */
    step = 20;  /* الخطوة */
    
    fahr = lower;
    celsius = 5 * (fahr - 32) / 9;  /* تحويل فهرنهايت إلى مئوي */
    
    printf("%d\t%d\n", fahr, celsius);  /* \t تعني مسافة جدولية */
}
