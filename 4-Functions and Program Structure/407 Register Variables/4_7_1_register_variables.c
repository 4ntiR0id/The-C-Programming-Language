/*
 * register_variables.c
 * 
 * Register variables hint the compiler to use fast registers.
 * The compiler may ignore the hint.
 */

#include <stdio.h>

main()
{
    register int i;             /* طلب استخدام سجل سريع */
    int sum = 0;
    
    for (i = 0; i < 1000; i++)  /* مفيد للمتغيرات المستخدمة كثيراً */
        sum += i;
    
    printf("%d\n", sum);
    
    /* لا يمكن أخذ عنوان متغير register */
}
