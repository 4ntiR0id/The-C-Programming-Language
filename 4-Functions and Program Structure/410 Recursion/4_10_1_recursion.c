/*
 * recursion.c
 * 
 * A function can call itself.
 * Each call gets its own set of local variables.
 */

#include <stdio.h>

int factorial(int n);

main()
{
    int result;
    
    result = factorial(5);
    printf("%d\n", result);
}

int factorial(int n)
{
    if (n <= 1)
        return 1;               /* حالة الإيقاف */
    else
        return n * factorial(n - 1);  /* استدعاء ذاتي */
}

/* factorial(5) = 5 * factorial(4) = 5 * 4 * 3 * 2 * 1 */
