/*
 * function_pointers.c
 * 
 * A pointer can point to a function.
 * This allows passing functions as arguments.
 */

#include <stdio.h>

int add(int a, int b);
int multiply(int a, int b);
int compute(int (*func)(int, int), int x, int y);

main()
{
    int result;
    
    result = compute(add, 5, 3);        /* تمرير دالة */
    printf("%d\n", result);
    
    result = compute(multiply, 5, 3);
    printf("%d\n", result);
}

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int compute(int (*func)(int, int), int x, int y)
{
    return (*func)(x, y);               /* استدعاء الدالة عبر المؤشر */
}
