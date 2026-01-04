/*
 * address_arithmetic.c
 * 
 * Adding to a pointer moves it by that many elements.
 * The compiler scales by the size of the type.
 */

#include <stdio.h>

main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p;
    
    p = a;                      /* يشير للعنصر الأول */
    
    printf("%d\n", *p);         /* 10 */
    
    p++;                        /* تقدم عنصراً واحداً */
    printf("%d\n", *p);         /* 20 */
    
    p += 2;                     /* تقدم عنصرين */
    printf("%d\n", *p);         /* 40 */
}
