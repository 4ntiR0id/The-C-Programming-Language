/*
 * scope_rules.c
 * 
 * Local variables hide external variables with the same name.
 * Each variable is visible only in its scope.
 */

#include <stdio.h>

int x = 10;                     /* متغير خارجي */

void func1(void);
void func2(void);

main()
{
    printf("%d\n", x);          /* المتغير الخارجي */
    func1();
    func2();
}

void func1(void)
{
    int x = 20;                 /* متغير محلي يخفي الخارجي */
    printf("%d\n", x);
}

void func2(void)
{
    printf("%d\n", x);          /* المتغير الخارجي مرة أخرى */
}
