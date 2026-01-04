/*
 * function_definitions.c
 * 
 * A function encapsulates a computation for reuse.
 * Functions make programs easier to understand and modify.
 */

#include <stdio.h>

int power(int m, int n);  /* إعلان الدالة */

main()
{
    int i;
    
    for (i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)  /* تعريف الدالة */
{
    int i, p;
    
    p = 1;
    for (i = 1; i <= n; i++)
        p = p * base;
    return p;  /* إرجاع النتيجة */
}
