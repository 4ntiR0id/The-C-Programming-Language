/*
 * creat_syscall.c
 * 
 * creat creates a new file or truncates an existing one.
 * It is equivalent to open with specific flags.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
    int fd;
    
    fd = creat("newfile.txt", 0644);    /* إنشاء ملف جديد */
    if (fd == -1) {
        printf("Cannot create file\n");
        return 1;
    }
    
    write(fd, "test\n", 5);
    close(fd);
    
    /* creat يعادل: open(name, O_WRONLY | O_CREAT | O_TRUNC, mode) */
}
