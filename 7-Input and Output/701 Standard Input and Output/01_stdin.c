/*
 * stdin.c
 * 
 * stdin is the standard input stream.
 * It normally reads from the keyboard.
 */

#include <stdio.h>

main()
{
    int c;
    
    printf("Type a character: ");
    c = getchar();              /* قراءة من stdin */
    
    printf("You typed: ");
    putchar(c);                 /* طباعة إلى stdout */
    printf("\n");
    
    /* stdin يمكن إعادة توجيهه من ملف */
}
