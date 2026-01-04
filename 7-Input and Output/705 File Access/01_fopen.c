/*
 * fopen.c
 * 
 * fopen opens a file and returns a file pointer.
 * NULL is returned if the file cannot be opened.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    
    fp = fopen("test.txt", "r");    /* فتح للقراءة */
    if (fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    
    printf("File opened successfully\n");
    
    fclose(fp);
    
    /* الأوضاع: "r" قراءة، "w" كتابة، "a" إضافة */
}
