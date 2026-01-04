/*
 * lseek_syscall.c
 * 
 * lseek moves the file position pointer.
 * It allows reading or writing at any location.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd;
    char buf[10];
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return 1;
    
    lseek(fd, 10, SEEK_SET);        /* الانتقال للبايت 10 */
    read(fd, buf, 5);
    
    lseek(fd, -5, SEEK_CUR);        /* الرجوع 5 بايتات */
    
    lseek(fd, 0, SEEK_END);         /* الانتقال للنهاية */
    
    close(fd);
}
