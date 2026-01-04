/*
 * external_variables.c
 * 
 * External variables are visible to all functions in a file.
 * They provide a way to share data between functions.
 */

#include <stdio.h>

int max;  /* متغير خارجي */

void find_max(int a, int b);

main()
{
    find_max(10, 20);
    printf("max = %d\n", max);  /* يمكن قراءة max من أي دالة */
}

void find_max(int a, int b)
{
    if (a > b)
        max = a;  /* تعديل المتغير الخارجي */
    else
        max = b;
}
