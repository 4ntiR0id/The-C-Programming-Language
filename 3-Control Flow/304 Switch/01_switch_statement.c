/*
 * switch_statement.c
 * 
 * The switch statement tests a value against several constants.
 * It is clearer than many if-else statements for simple tests.
 */

#include <stdio.h>

main()
{
    int day = 3;
    
    switch (day) {          /* اختبر قيمة day */
        case 1:             /* إذا كانت 1 */
            printf("Monday\n");
            break;          /* اخرج من switch */
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:            /* إذا لم تطابق أي case */
            printf("Other day\n");
    }
}
