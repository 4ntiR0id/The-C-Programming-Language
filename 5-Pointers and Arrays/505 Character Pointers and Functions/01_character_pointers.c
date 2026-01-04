/*
 * character_pointers.c
 * 
 * Character pointers are used for strings.
 * String literals return a pointer to char.
 */

#include <stdio.h>

main()
{
    char *s;
    
    s = "hello";                /* s يشير لأول حرف في النص */
    
    printf("%s\n", s);
    printf("%c\n", *s);         /* أول حرف */
    printf("%c\n", *(s + 1));   /* ثاني حرف */
    
    /* يمكن استخدام s[i] أو *(s+i) */
}
