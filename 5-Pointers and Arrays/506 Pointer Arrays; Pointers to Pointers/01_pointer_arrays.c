/*
 * pointer_arrays.c
 * 
 * An array can hold pointers.
 * This is useful for arrays of strings.
 */

#include <stdio.h>

main()
{
    char *names[3];             /* مصفوفة من 3 مؤشرات */
    
    names[0] = "Alice";
    names[1] = "Bob";
    names[2] = "Charlie";
    
    printf("%s\n", names[0]);
    printf("%s\n", names[1]);
    printf("%s\n", names[2]);
}
