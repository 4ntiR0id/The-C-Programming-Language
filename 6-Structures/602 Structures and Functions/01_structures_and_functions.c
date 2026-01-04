/*
 * structures_and_functions.c
 * 
 * Structures can be passed to functions.
 * The function receives a copy of the structure.
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point add_points(struct point p1, struct point p2);

main()
{
    struct point a = {10, 20};      /* تهيئة */
    struct point b = {30, 40};
    struct point result;
    
    result = add_points(a, b);
    printf("%d %d\n", result.x, result.y);
}

struct point add_points(struct point p1, struct point p2)
{
    struct point sum;
    
    sum.x = p1.x + p2.x;
    sum.y = p1.y + p2.y;
    return sum;                     /* إرجاع هيكل */
}
