/*
 * fputs.c
 * 
 * fputs writes a string to a file.
 * It does not add a newline automatically.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    
    fp = fopen("output.txt", "w");
    if (fp == NULL)
        return 1;
    
    fputs("First line\n", fp);      /* يجب إضافة \n يدوياً */
    fputs("Second line\n", fp);
    
    fclose(fp);
}
