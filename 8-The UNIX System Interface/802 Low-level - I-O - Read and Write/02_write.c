/*
 * write_syscall.c
 * 
 * write transfers bytes from a buffer to a file.
 * It returns the number of bytes written.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

main()
{
    int fd, n;
    char *message = "Hello, file\n";
    
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
        return 1;
    
    n = write(fd, message, strlen(message));    /* كتابة النص */
    if (n != strlen(message)) {
        printf("Write error\n");
        close(fd);
        return 1;
    }
    
    close(fd);
}
