/*
 * getchar.c
 * 
 * getchar reads the next character from the input.
 * It returns the character as an integer value.
 */

#include <stdio.h>

main()
{
    int c;  /* نستخدم int وليس char لأن getchar تعيد EOF أيضاً */
    
    c = getchar();  /* قراءة حرف واحد */
    
    while (c != EOF) {  /* EOF تعني نهاية الملف */
        putchar(c);  /* طباعة الحرف */
        c = getchar();  /* قراءة الحرف التالي */
    }
}
