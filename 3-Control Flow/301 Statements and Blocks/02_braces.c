/*
 * braces.c
 * 
 * Braces group statements together.
 * They define the scope of variables and control structures.
 */

#include <stdio.h>

main()
{
    int i;
    
    for (i = 0; i < 5; i++) {   /* الأقواس تجمع عدة جمل */
        int square = i * i;
        printf("%d %d\n", i, square);
    }
    
    /* بدون أقواس، جملة واحدة فقط تتبع for */
    for (i = 0; i < 3; i++)
        printf("%d\n", i);
}
