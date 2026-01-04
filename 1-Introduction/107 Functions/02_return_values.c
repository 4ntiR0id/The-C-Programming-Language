/*
 * return_values.c
 * 
 * A function can return a value to its caller.
 * The return statement specifies what value to send back.
 */

#include <stdio.h>

int max(int a, int b);  /* دالة تعيد القيمة الأكبر */

main()
{
    int x, y, result;
    
    x = 15;
    y = 20;
    result = max(x, y);  /* استقبال القيمة المرجعة */
    
    printf("max = %d\n", result);
}

int max(int a, int b)
{
    if (a > b)
        return a;  /* إرجاع a إذا كانت أكبر */
    else
        return b;  /* وإلا إرجاع b */
}
