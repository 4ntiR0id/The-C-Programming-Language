/*
 * unlink_syscall.c
 * 
 * unlink removes a file from the directory.
 * The file is deleted when the last reference is closed.
 */

#include <stdio.h>
#include <unistd.h>

main()
{
    if (unlink("tempfile.txt") == -1) {     /* حذف الملف */
        printf("Cannot delete file\n");
        return 1;
    }
    
    printf("File deleted\n");
    
    /* إذا كان الملف مفتوحاً، يبقى حتى يُغلق */
}
