/*
 * scope_rules.c
 * 
 * A variable's scope determines where it can be used.
 * Local variables hide external ones with the same name.
 */

#include <stdio.h>

int x = 5;  /* متغير خارجي */

void function1(void);
void function2(void);

main()
{
    printf("%d\n", x);  /* المتغير الخارجي */
    function1();
    function2();
}

void function1(void)
{
    int x = 10;  /* متغير محلي يخفي الخارجي */
    printf("%d\n", x);
}

void function2(void)
{
    printf("%d\n", x);  /* المتغير الخارجي مرة أخرى */
}
