/*
 * character_constants.c
 * 
 * A character constant is a single character in single quotes.
 * Escape sequences represent special characters.
 */

#include <stdio.h>

main()
{
    char c1, c2, c3;
    
    c1 = 'A';           /* حرف عادي */
    c2 = '\n';          /* سطر جديد */
    c3 = '\t';          /* مسافة جدولية */
    
    printf("%c", c1);
    printf("%c", c2);
    printf("%c", c3);
    
    /* أمثلة أخرى: '\0' نهاية نص، '\\' شرطة مائلة، '\'' علامة اقتباس */
}
