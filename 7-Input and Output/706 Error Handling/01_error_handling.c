/*
 * error_handling.c
 * 
 * File operations can fail.
 * Always check return values for errors.
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    int c;
    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {               /* فحص الخطأ */
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }
    
    while ((c = fgetc(fp)) != EOF) {
        if (ferror(fp)) {           /* فحص خطأ أثناء القراءة */
            fprintf(stderr, "Read error\n");
            break;
        }
        putchar(c);
    }
    
    fclose(fp);
}
