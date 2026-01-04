/*
 * struct_definition.c
 * 
 * A structure groups related variables together.
 * Each variable in a structure is called a member.
 */

#include <stdio.h>

struct point {              /* تعريف نوع جديد */
    int x;
    int y;
};

main()
{
    struct point p;         /* متغير من نوع point */
    
    p.x = 10;               /* الوصول للعضو باستخدام النقطة */
    p.y = 20;
    
    printf("%d %d\n", p.x, p.y);
}
