/*
 * header_files.c
 * 
 * Header files contain declarations shared among source files.
 * They keep declarations consistent.
 */

#include <stdio.h>              /* ملف رأس من المكتبة القياسية */

/* في برنامج كبير، نضع التصريحات في ملف .h:
 * 
 * mylib.h:
 * int add(int a, int b);
 * int multiply(int a, int b);
 * 
 * ثم في الملف .c:
 * #include "mylib.h"
 */

main()
{
    printf("Header files organize declarations\n");
}
