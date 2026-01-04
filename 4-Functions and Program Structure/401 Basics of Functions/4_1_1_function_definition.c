/*
 * function_definition.c
 * 
 * A function is a self-contained unit of code.
 * It takes arguments and returns a value.
 */

#include <stdio.h>

int power(int base, int n);     /* إعلان الدالة */

main()
{
    int result;
    
    result = power(2, 10);      /* استدعاء الدالة */
    printf("%d\n", result);
}

int power(int base, int n)      /* تعريف الدالة */
{
    int i, p;
    
    p = 1;
    for (i = 1; i <= n; i++)
        p = p * base;
    return p;                   /* إرجاع النتيجة */
}
