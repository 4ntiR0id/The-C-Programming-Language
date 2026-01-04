/*
 * do_while.c
 * 
 * The do-while loop tests after each iteration.
 * It always executes at least once.
 */

#include <stdio.h>

main()
{
    int i = 0;
    
    do {                    /* نفذ الجسم أولاً */
        printf("%d\n", i);
        i++;
    } while (i < 5);        /* ثم اختبر الشرط */
    
    /* الفرق عن while: تنفذ مرة واحدة على الأقل حتى لو كان الشرط خاطئاً */
}
