/*
 * open_syscall.c
 * 
 * open is a system call that opens a file.
 * It returns a file descriptor, a small integer.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd;
    
    fd = open("test.txt", O_RDONLY);    /* فتح للقراءة فقط */
    if (fd == -1) {
        printf("Cannot open file\n");
        return 1;
    }
    
    printf("File descriptor: %d\n", fd);
    
    close(fd);
    
    /* الأوضاع: O_RDONLY، O_WRONLY، O_RDWR */
}
