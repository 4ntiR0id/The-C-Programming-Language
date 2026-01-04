/*
 * storage_duration.c
 * 
 * External variables exist for the entire program run.
 * Local variables exist only during function execution.
 */

#include <stdio.h>

int counter = 0;  /* موجود طوال تشغيل البرنامج */

void count(void);

main()
{
    count();
    count();
    count();
}

void count(void)
{
    int local = 0;  /* يُنشأ ويُدمر عند كل استدعاء */
    
    local++;
    counter++;  /* يحتفظ بقيمته بين الاستدعاءات */
    
    printf("local = %d, counter = %d\n", local, counter);
}
