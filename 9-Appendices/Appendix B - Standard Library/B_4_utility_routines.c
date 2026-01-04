/*
 * utility_routines.c
 * 
 * Utility functions provide general-purpose operations.
 * They are declared in stdlib.h and other headers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

main()
{
    char *str;
    int num;
    
    /* تحويل نص لعدد */
    num = atoi("123");              /* نص إلى int */
    atof("3.14");                   /* نص إلى double */
    atol("123456");                 /* نص إلى long */
    
    /* ذاكرة ديناميكية */
    str = malloc(100);              /* تخصيص ذاكرة */
    if (str != NULL) {
        free(str);                  /* تحرير الذاكرة */
    }
    
    /* أحرف */
    isdigit('5');                   /* هل رقم؟ */
    isalpha('A');                   /* هل حرف؟ */
    toupper('a');                   /* تحويل لكبير */
    tolower('A');                   /* تحويل لصغير */
    
    /* عشوائي */
    rand();                         /* رقم عشوائي */
    srand(42);                      /* تهيئة المولد */
    
    /* خروج */
    exit(0);                        /* إنهاء البرنامج */
}
