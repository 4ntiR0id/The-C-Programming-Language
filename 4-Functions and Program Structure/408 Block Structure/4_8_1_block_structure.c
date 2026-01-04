/*
 * block_structure.c
 * 
 * Variables can be declared in any block.
 * They exist only within that block.
 */

#include <stdio.h>

main()
{
    int x = 10;
    
    {                           /* كتلة جديدة */
        int y = 20;             /* y موجود فقط في هذه الكتلة */
        printf("%d %d\n", x, y);
    }
    
    printf("%d\n", x);          /* x موجود */
    /* printf("%d\n", y);       خطأ: y غير موجود هنا */
}
