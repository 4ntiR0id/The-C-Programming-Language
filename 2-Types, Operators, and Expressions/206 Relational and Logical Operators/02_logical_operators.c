/*
 * logical_operators.c
 * 
 * Logical operators combine conditions.
 * They work with true (non-zero) and false (zero) values.
 */

#include <stdio.h>

main()
{
    int a = 5, b = 10, c = 0;
    
    printf("%d\n", a && b);  /* AND: 1 لأن كلاهما ليس صفر */
    printf("%d\n", a && c);  /* AND: 0 لأن c صفر */
    printf("%d\n", a || c);  /* OR: 1 لأن a ليس صفر */
    printf("%d\n", c || 0);  /* OR: 0 لأن كلاهما صفر */
    printf("%d\n", !a);      /* NOT: 0 لأن a ليس صفر */
    printf("%d\n", !c);      /* NOT: 1 لأن c صفر */
}
