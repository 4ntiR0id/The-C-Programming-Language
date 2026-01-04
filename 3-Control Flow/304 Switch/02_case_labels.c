/*
 * case_labels.c
 * 
 * Case labels can be grouped together.
 * Execution falls through unless break is used.
 */

#include <stdio.h>

main()
{
    int c = 'a';
    
    switch (c) {
        case 'a':           /* يمكن كتابة عدة case متتالية */
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("vowel\n");
            break;          /* break ضروري لمنع السقوط للحالة التالية */
        case ' ':
        case '\t':
        case '\n':
            printf("white space\n");
            break;
        default:
            printf("consonant\n");
    }
}
