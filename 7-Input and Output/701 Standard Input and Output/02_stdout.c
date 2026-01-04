/*
 * stdout.c
 * 
 * stdout is the standard output stream.
 * It normally writes to the screen.
 */

#include <stdio.h>

main()
{
    fprintf(stdout, "Hello, world\n");  /* كتابة مباشرة إلى stdout */
    
    printf("Same as stdout\n");         /* printf تكتب إلى stdout */
    
    /* stdout يمكن إعادة توجيهه إلى ملف */
}
