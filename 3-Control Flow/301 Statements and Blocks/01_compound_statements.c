/*
 * compound_statements.c
 * 
 * A compound statement groups several statements into one.
 * It is treated as a single statement by the language.
 */

#include <stdio.h>

main()
{
    int x = 5;
    
    {                       /* بداية جملة مركبة */
        int y = 10;         /* متغير محلي للكتلة */
        x = x + y;
        printf("%d\n", x);
    }                       /* نهاية الجملة المركبة */
    
    /* y غير موجود هنا */
}
