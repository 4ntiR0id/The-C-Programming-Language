/*
 * strings.c
 * 
 * A string is an array of characters ending with '\0'.
 * The null character marks where the string ends.
 */

#include <stdio.h>

main()
{
    char s[10];  /* مصفوفة من الحروف */
    
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '\0';  /* نهاية النص */
    
    printf("%s\n", s);  /* %s للنصوص */
    
    /* يمكن أيضاً: char s[] = "hello"; */
}
