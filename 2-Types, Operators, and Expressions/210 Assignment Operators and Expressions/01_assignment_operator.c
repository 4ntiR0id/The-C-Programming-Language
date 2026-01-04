/*
 * assignment_operator.c
 * 
 * The assignment operator stores a value in a variable.
 * It returns the value assigned.
 */

#include <stdio.h>

main()
{
    int x, y, z;
    
    x = 5;              /* إسناد بسيط */
    y = x;              /* نسخ قيمة x إلى y */
    z = (x = 10);       /* x يصبح 10، ثم z يأخذ نفس القيمة */
    
    printf("%d %d %d\n", x, y, z);
    
    /* يمكن ربط عدة إسنادات: a = b = c = 0; */
}
