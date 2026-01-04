/*
 * read_syscall.c
 * 
 * read transfers bytes from a file to a buffer.
 * It returns the number of bytes read.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd, n;
    char buf[100];
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return 1;
    
    n = read(fd, buf, sizeof(buf) - 1); /* قراءة حتى 99 بايت */
    if (n > 0) {
        buf[n] = '\0';                  /* إضافة نهاية النص */
        printf("%s", buf);
    }
    
    close(fd);
    
    /* read تعيد 0 عند نهاية الملف، -1 عند الخطأ */
}
