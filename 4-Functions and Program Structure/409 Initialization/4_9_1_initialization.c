/*
 * initialization.c
 * 
 * External and static variables are initialized to zero by default.
 * Local variables have undefined initial values.
 */

#include <stdio.h>

int global;                     /* يُهيأ بـ 0 تلقائياً */
static int file_static;         /* يُهيأ بـ 0 تلقائياً */

main()
{
    int local;                  /* قيمة غير معرفة */
    static int local_static;    /* يُهيأ بـ 0 تلقائياً */
    
    int initialized = 5;        /* تهيئة صريحة */
    
    printf("%d\n", global);
    printf("%d\n", local_static);
    printf("%d\n", initialized);
    
    /* local له قيمة عشوائية - لا تستخدمه قبل الإسناد */
}
