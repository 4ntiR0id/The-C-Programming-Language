/*
 * fclose.c
 * 
 * fclose closes a file and flushes buffers.
 * It should be called when done with a file.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    
    fp = fopen("output.txt", "w");
    if (fp == NULL)
        return 1;
    
    fprintf(fp, "Hello, file\n");   /* كتابة للملف */
    
    fclose(fp);                     /* إغلاق الملف */
    
    /* عدم إغلاق الملف قد يفقد البيانات */
}
