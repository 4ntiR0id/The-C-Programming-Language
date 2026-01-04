/*
 * standard_io_library.c
 * 
 * The standard I/O library provides file and stream operations.
 * It is declared in stdio.h.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    int c;
    
    /* فتح وإغلاق */
    fp = fopen("file.txt", "r");
    if (fp != NULL) {
        
        /* قراءة */
        c = fgetc(fp);              /* حرف واحد */
        c = getc(fp);               /* مثل fgetc */
        
        /* كتابة */
        fputc('A', fp);
        putc('B', fp);
        
        /* طباعة منسقة */
        fprintf(fp, "%d %s\n", 42, "hello");
        
        /* قراءة منسقة */
        fscanf(fp, "%d", &c);
        
        fclose(fp);
    }
}
