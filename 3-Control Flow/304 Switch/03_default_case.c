/*
 * default_case.c
 * 
 * The default case catches values that match no other case.
 * It is optional but good practice.
 */

#include <stdio.h>

main()
{
    int digit = 7;
    
    switch (digit) {
        case 0:
            printf("zero\n");
            break;
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        default:            /* أي قيمة أخرى */
            printf("other digit\n");
            break;          /* break في default اختياري لكن موصى به */
    }
}
