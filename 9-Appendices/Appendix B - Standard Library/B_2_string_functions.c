/*
 * string_functions.c
 * 
 * String functions manipulate character arrays.
 * They are declared in string.h.
 */

#include <stdio.h>
#include <string.h>

main()
{
    char s1[50] = "hello";
    char s2[50] = "world";
    int len, cmp;
    
    /* طول النص */
    len = strlen(s1);                   /* 5 */
    
    /* نسخ */
    strcpy(s1, "new");                  /* s1 يصبح "new" */
    strncpy(s1, "hello", 3);            /* نسخ 3 أحرف فقط */
    
    /* ربط */
    strcat(s1, s2);                     /* إضافة s2 لـ s1 */
    strncat(s1, s2, 3);                 /* إضافة 3 أحرف */
    
    /* مقارنة */
    cmp = strcmp(s1, s2);               /* 0 إذا متساوية */
    cmp = strncmp(s1, s2, 3);           /* مقارنة 3 أحرف */
    
    /* بحث */
    strchr(s1, 'e');                    /* أول ظهور لحرف */
    strstr(s1, "ll");                   /* أول ظهور لنص */
}
