/*
 * comments.c
 * 
 * Comments explain code to human readers.
 * The compiler ignores everything between slash-star and star-slash.
 */

#include <stdio.h>

main()
{
    int x;  /* تعليق قصير في نهاية السطر */
    
    /*
     * تعليق على عدة أسطر
     * يستخدم لشرح فكرة أطول
     */
    
    x = 5;  /* التعليقات لا تؤثر على تنفيذ البرنامج */
    
    /* x = 10; */ /* هذا السطر لن ينفذ لأنه داخل تعليق */
    
    printf("%d\n", x);
}
