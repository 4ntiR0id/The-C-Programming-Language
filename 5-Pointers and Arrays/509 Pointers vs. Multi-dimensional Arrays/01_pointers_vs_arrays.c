/*
 * pointers_vs_arrays.c
 * 
 * Pointers and arrays are different.
 * An array name is a constant pointer, not a variable.
 */

#include <stdio.h>

main()
{
    char array[] = "hello";     /* مصفوفة من الحروف */
    char *pointer = "world";    /* مؤشر لنص */
    
    printf("%c\n", array[0]);
    printf("%c\n", pointer[0]);
    
    pointer = array;            /* يمكن تغيير المؤشر */
    /* array = pointer;         خطأ: لا يمكن تغيير اسم المصفوفة */
    
    printf("%s\n", pointer);
}
