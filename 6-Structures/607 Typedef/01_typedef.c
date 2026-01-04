/*
 * typedef.c
 * 
 * Typedef creates a new name for a type.
 * It makes declarations shorter and clearer.
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

typedef struct point Point;     /* اسم جديد للنوع */

main()
{
    Point p1, p2;               /* بدلاً من struct point p1, p2; */
    
    p1.x = 10;
    p1.y = 20;
    
    p2 = p1;
    
    printf("%d %d\n", p2.x, p2.y);
}
