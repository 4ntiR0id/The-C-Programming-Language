/*
 * static_global.c
 * 
 * Static global variables are visible only in their source file.
 * They provide privacy from other files.
 */

#include <stdio.h>

static int secret = 42;         /* مرئي فقط في هذا الملف */

void show_secret(void);

main()
{
    show_secret();
}

void show_secret(void)
{
    printf("%d\n", secret);     /* يمكن الوصول داخل نفس الملف */
}

/* في ملف آخر، secret غير مرئي */
