/*
 * data_type_int.c
 * 
 * An int holds an integer value.
 * The size depends on the machine.
 */

#include <stdio.h>

main()
{
    int x;
    int count, total;
    
    x = 100;
    count = -50;        /* يمكن أن يكون موجباً أو سالباً */
    total = x + count;
    
    printf("%d\n", total);
}
