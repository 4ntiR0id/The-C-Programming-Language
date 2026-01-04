/*
 * unions.c
 * 
 * A union holds one of several types in the same memory.
 * Only one member can be used at a time.
 */

#include <stdio.h>

union data {                    /* نفس الذاكرة لكل الأعضاء */
    int i;
    float f;
    char str[20];
};

main()
{
    union data d;
    
    d.i = 10;
    printf("%d\n", d.i);
    
    d.f = 3.14;                 /* يكتب فوق i */
    printf("%f\n", d.f);
    
    /* d.i الآن غير صحيح لأن f كتب فوقه */
}
