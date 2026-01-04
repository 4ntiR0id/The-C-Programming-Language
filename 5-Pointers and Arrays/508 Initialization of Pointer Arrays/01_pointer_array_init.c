/*
 * pointer_array_initialization.c
 * 
 * Pointer arrays can be initialized with string literals.
 * This creates string tables.
 */

#include <stdio.h>

main()
{
    char *months[] = {          /* مصفوفة من النصوص */
        "January",
        "February",
        "March",
        "April",
        "May"
    };
    int i;
    
    for (i = 0; i < 5; i++)
        printf("%s\n", months[i]);
}
