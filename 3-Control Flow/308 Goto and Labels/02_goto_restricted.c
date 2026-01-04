/*
 * goto_restricted.c
 * 
 * Goto is best reserved for error handling and cleanup.
 * Overuse makes programs hard to follow.
 */

#include <stdio.h>

main()
{
    FILE *f1, *f2;
    
    f1 = fopen("file1.txt", "r");
    if (f1 == NULL)
        goto error;         /* إذا فشل، اذهب للتنظيف */
    
    f2 = fopen("file2.txt", "r");
    if (f2 == NULL)
        goto close_f1;      /* أغلق f1 قبل الخروج */
    
    /* استخدم الملفات */
    
    fclose(f2);
close_f1:
    fclose(f1);
error:
    printf("done\n");
}
