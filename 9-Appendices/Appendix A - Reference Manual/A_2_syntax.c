/*
 * syntax.c
 * 
 * Syntax defines how tokens combine to form valid statements.
 * Each construct has specific rules.
 */

#include <stdio.h>

main()
{
    /* تصريح: النوع + المعرف */
    int x;
    
    /* جملة: تعبير + فاصلة منقوطة */
    x = 5;
    
    /* جملة تحكم: if + شرط + جملة */
    if (x > 0)
        printf("positive\n");
    
    /* حلقة: while + شرط + جملة */
    while (x > 0)
        x--;
}
