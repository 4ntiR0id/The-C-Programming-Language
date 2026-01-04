/*
 * conditional_expression.c
 * 
 * The conditional operator ?: chooses between two values.
 * It is a compact form of if-else.
 */

#include <stdio.h>

main()
{
    int a = 5, b = 10;
    int max, min;
    
    max = (a > b) ? a : b;  /* إذا a أكبر، خذ a، وإلا خذ b */
    printf("%d\n", max);
    
    min = (a < b) ? a : b;
    printf("%d\n", min);
    
    /* الصيغة: شرط ? قيمة_إذا_صح : قيمة_إذا_خطأ */
}
