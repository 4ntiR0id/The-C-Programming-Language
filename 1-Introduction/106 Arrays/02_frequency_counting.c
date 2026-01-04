/*
 * frequency_counting.c
 * 
 * Count the occurrences of each digit in the input.
 * This demonstrates how arrays store related data.
 */

#include <stdio.h>

main()
{
    int c, i, nwhite, nother;
    int ndigit[10];  /* عداد لكل رقم من 0 إلى 9 */
    
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;  /* تهيئة المصفوفة */
    
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')  /* إذا كان رقماً */
            ndigit[c - '0']++;  /* زد العداد المناسب */
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;  /* مسافة أو سطر جديد أو تاب */
        else
            nother++;  /* حرف آخر */
    }
    
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
