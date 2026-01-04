/*
 * initialization.c
 * 
 * Variables can be initialized when declared.
 * This combines declaration and assignment in one step.
 */

#include <stdio.h>

main()
{
    int x = 5;          /* تعريف مع قيمة ابتدائية */
    int a = 1, b = 2, c = 3;  /* عدة متغيرات مع قيم */
    float pi = 3.14;
    char ch = 'A';
    
    printf("%d %d %d %d\n", x, a, b, c);
    printf("%.2f %c\n", pi, ch);
}
