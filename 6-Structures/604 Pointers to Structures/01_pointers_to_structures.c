/*
 * pointers_to_structures.c
 * 
 * A pointer can point to a structure.
 * The -> operator accesses members through a pointer.
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

main()
{
    struct point p = {10, 20};
    struct point *pp;
    
    pp = &p;                        /* مؤشر للهيكل */
    
    printf("%d %d\n", (*pp).x, (*pp).y);    /* طريقة */
    printf("%d %d\n", pp->x, pp->y);        /* أسهل وأوضح */
}
