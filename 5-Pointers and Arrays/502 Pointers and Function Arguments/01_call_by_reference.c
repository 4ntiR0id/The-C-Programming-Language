/*
 * call_by_reference.c
 * 
 * Passing a pointer lets a function modify the caller's variable.
 * This is how C achieves call by reference.
 */

#include <stdio.h>

void swap(int *a, int *b);

main()
{
    int x = 5, y = 10;
    
    printf("before: x=%d y=%d\n", x, y);
    swap(&x, &y);               /* تمرير العناوين */
    printf("after: x=%d y=%d\n", x, y);
}

void swap(int *a, int *b)
{
    int temp;
    
    temp = *a;                  /* الوصول للقيم عبر المؤشرات */
    *a = *b;
    *b = temp;
}
