/*
 * misc_functions.c
 * 
 * Several utility functions support I/O operations.
 * They handle positioning, buffering, and testing.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    int c;
    
    fp = fopen("test.txt", "r");
    if (fp == NULL)
        return 1;
    
    c = fgetc(fp);                  /* قراءة حرف */
    ungetc(c, fp);                  /* إرجاع الحرف */
    
    fseek(fp, 0, SEEK_END);         /* الانتقال لنهاية الملف */
    long size = ftell(fp);          /* معرفة الموضع */
    rewind(fp);                     /* العودة للبداية */
    
    printf("File size: %ld\n", size);
    
    fclose(fp);
}
