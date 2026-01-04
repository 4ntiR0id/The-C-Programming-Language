/*
 * fseek_implementation.c
 * 
 * This shows how fseek might be implemented using lseek.
 * It demonstrates the relationship between high and low level I/O.
 */

#include <stdio.h>
#include <unistd.h>

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int my_fseek(FILE *fp, long offset, int whence)
{
    int fd;
    
    fd = fileno(fp);                /* الحصول على واصف الملف */
    
    if (lseek(fd, offset, whence) == -1)    /* استخدام lseek */
        return -1;
    
    return 0;
}

main()
{
    FILE *fp;
    
    fp = fopen("test.txt", "r");
    if (fp == NULL)
        return 1;
    
    my_fseek(fp, 10, SEEK_SET);     /* تنفيذنا الخاص */
    
    fclose(fp);
}
