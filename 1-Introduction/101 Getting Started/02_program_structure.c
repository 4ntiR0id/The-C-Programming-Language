/*
 * program_structure.c
 * 
 * This shows the basic structure of a C program.
 * Every program has functions, and main is where execution begins.
 */

#include <stdio.h>  /* ملفات الرأس توفر وظائف جاهزة */

main()  /* النقطة التي يبدأ منها البرنامج */
{
    int a, b, c;  /* نعرف المتغيرات قبل استخدامها */
    
    a = 5;  /* إسناد قيمة */
    b = 3;
    c = a + b;  /* عملية حسابية */
    
    printf("sum is %d\n", c);  /* %d تعني عدد صحيح */
}
