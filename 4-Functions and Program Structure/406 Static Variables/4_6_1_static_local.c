/*
 * static_local.c
 * 
 * Static local variables keep their value between function calls.
 * They are initialized only once.
 */

#include <stdio.h>

void counter(void);

main()
{
    counter();
    counter();
    counter();
}

void counter(void)
{
    static int count = 0;       /* تُنشأ مرة واحدة فقط */
    
    count++;
    printf("%d\n", count);      /* تحتفظ بقيمتها بين الاستدعاءات */
}
