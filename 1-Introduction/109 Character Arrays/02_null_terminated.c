/*
 * null_terminated.c
 * 
 * String functions rely on the null terminator to find the end.
 * Without '\0', functions would read beyond the string.
 */

#include <stdio.h>

int length(char s[]);

main()
{
    char text[] = "hello";  /* يضيف المترجم '\0' تلقائياً */
    
    printf("%d\n", length(text));
}

int length(char s[])
{
    int i;
    
    i = 0;
    while (s[i] != '\0')  /* استمر حتى نهاية النص */
        i++;
    return i;
}
