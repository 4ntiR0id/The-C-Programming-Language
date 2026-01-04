/*
 * scanf.c
 * 
 * scanf reads formatted input.
 * It returns the number of items successfully read.
 */

#include <stdio.h>

main()
{
    int i;
    float f;
    char s[100];
    
    printf("Enter integer, float, string: ");
    scanf("%d %f %s", &i, &f, s);   /* تمرير العناوين */
    
    printf("int: %d\n", i);
    printf("float: %f\n", f);
    printf("string: %s\n", s);
    
    /* scanf يتخطى المسافات البيضاء تلقائياً */
}
