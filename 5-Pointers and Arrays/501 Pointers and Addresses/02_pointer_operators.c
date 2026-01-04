/*
 * pointer_operators.c
 * 
 * The & operator gets an address.
 * The * operator accesses the value at an address.
 */

#include <stdio.h>

main()
{
    int x = 10;
    int *p;
    
    p = &x;                     /* p الآن يشير إلى x */
    
    *p = 20;                    /* تغيير القيمة عند العنوان */
    
    printf("%d\n", x);          /* x تغيرت إلى 20 */
    printf("%d\n", *p);         /* نفس القيمة */
}
