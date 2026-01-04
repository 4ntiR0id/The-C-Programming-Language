/*
 * address_concept.c
 * 
 * Every variable has an address in memory.
 * A pointer holds the address of another variable.
 */

#include <stdio.h>

main()
{
    int x = 5;
    int *p;                     /* p مؤشر لعدد صحيح */
    
    p = &x;                     /* & تعطي عنوان x */
    
    printf("x = %d\n", x);
    printf("address of x = %p\n", (void*)p);
    printf("value at address = %d\n", *p);  /* * تعطي القيمة */
}
