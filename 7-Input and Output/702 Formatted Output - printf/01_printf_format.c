/*
 * printf_format.c
 * 
 * printf formats output according to a format string.
 * Each % specification converts one argument.
 */

#include <stdio.h>

main()
{
    int i = 42;
    float f = 3.14;
    char c = 'A';
    char *s = "hello";
    
    printf("%d\n", i);              /* عدد صحيح */
    printf("%f\n", f);              /* عدد عشري */
    printf("%.2f\n", f);            /* رقمان بعد الفاصلة */
    printf("%c\n", c);              /* حرف */
    printf("%s\n", s);              /* نص */
    printf("%5d\n", i);             /* عرض 5 خانات */
    printf("%-5d\n", i);            /* محاذاة لليسار */
}
