/*
 * close_syscall.c
 * 
 * close releases a file descriptor.
 * It should be called when done with a file.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return 1;
    
    /* استخدام fd */
    
    if (close(fd) == -1) {              /* إغلاق واصف الملف */
        printf("Error closing file\n");
        return 1;
    }
    
    /* fd لم يعد صالحاً بعد close */
}
