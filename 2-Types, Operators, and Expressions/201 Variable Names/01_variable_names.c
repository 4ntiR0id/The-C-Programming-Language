/*
 * variable_names.c
 * 
 * Variable names must begin with a letter or underscore.
 * Choose names that describe the variable's purpose.
 */

#include <stdio.h>

main()
{
    int count;          /* اسم واضح */
    int i, j, k;        /* أسماء قصيرة للعدادات */
    int user_age;       /* يمكن استخدام الشرطة السفلية */
    int _temp;          /* يبدأ بشرطة سفلية */
    
    /* int 2count;      خطأ: لا يبدأ برقم */
    /* int user-age;    خطأ: لا يحتوي على شرطة */
    
    count = 10;
    printf("%d\n", count);
}
