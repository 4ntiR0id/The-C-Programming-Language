/*
 * pointers_to_pointers.c
 * 
 * A pointer can point to another pointer.
 * This creates multiple levels of indirection.
 */

#include <stdio.h>

main()
{
    int x = 5;
    int *p;
    int **pp;                   /* مؤشر لمؤشر */
    
    p = &x;
    pp = &p;                    /* pp يشير إلى p */
    
    printf("%d\n", x);
    printf("%d\n", *p);         /* القيمة عبر p */
    printf("%d\n", **pp);       /* القيمة عبر pp */
}
