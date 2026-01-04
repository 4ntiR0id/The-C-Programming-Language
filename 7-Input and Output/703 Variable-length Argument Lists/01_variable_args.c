/*
 * variable_args.c
 * 
 * Functions can accept a variable number of arguments.
 * This is how printf handles any number of values.
 */

#include <stdio.h>
#include <stdarg.h>

void mini_printf(char *fmt, ...);

main()
{
    mini_printf("int: %d, float: %f\n", 42, 3.14);
}

void mini_printf(char *fmt, ...)
{
    va_list ap;                 /* قائمة الوسائط المتغيرة */
    
    va_start(ap, fmt);          /* تهيئة ap */
    
    /* في printf الحقيقي، fmt يُفحص لمعالجة % */
    vprintf(fmt, ap);           /* طباعة باستخدام قائمة الوسائط */
    
    va_end(ap);                 /* تنظيف */
}
