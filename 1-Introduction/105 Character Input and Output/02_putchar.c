/*
 * putchar.c
 * 
 * putchar prints a single character to the output.
 * It is the complement of getchar.
 */

#include <stdio.h>

main()
{
    int c;
    
    c = getchar();
    while (c != EOF) {
        putchar(c);  /* طباعة حرف واحد */
        c = getchar();
    }
    
    /* هذا البرنامج ينسخ المدخلات إلى المخرجات حرفاً بحرف */
}
