/*
 * array_declaration.c
 * 
 * An array is a collection of variables of the same type.
 * Array elements are numbered from 0 to n-1.
 */

#include <stdio.h>

main()
{
    int ndigit[10];  /* مصفوفة من 10 أعداد صحيحة */
    int i;
    
    for (i = 0; i < 10; i = i + 1)
        ndigit[i] = 0;  /* تهيئة كل عنصر بالصفر */
    
    ndigit[0] = 5;  /* العنصر الأول */
    ndigit[9] = 3;  /* العنصر الأخير */
    
    /* الفهرس يبدأ من 0 وينتهي عند 9 */
}
