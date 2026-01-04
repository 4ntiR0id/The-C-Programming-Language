/*
 * variable_declarations.c
 * 
 * Variables must be declared before use.
 * The declaration specifies the type and name.
 */

#include <stdio.h>

main()
{
    int x;              /* تعريف متغير واحد */
    int a, b, c;        /* تعريف عدة متغيرات */
    float price;
    char letter;
    
    x = 10;
    a = 1;
    b = 2;
    c = a + b;
    
    printf("%d %d\n", x, c);
}
