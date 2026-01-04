/*
 * data_type_char.c
 * 
 * A char holds a single character.
 * It is actually a small integer.
 */

#include <stdio.h>

main()
{
    char c;
    char letter;
    
    c = 'A';            /* حرف واحد بين علامتي اقتباس مفردة */
    letter = 'x';
    
    printf("%c\n", c);  /* %c لطباعة حرف */
    printf("%d\n", c);  /* %d لطباعة قيمته العددية */
}
