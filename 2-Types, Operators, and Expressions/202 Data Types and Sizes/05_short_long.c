/*
 * data_type_short_long.c
 * 
 * short and long are variations of int.
 * short uses less space, long can hold larger values.
 */

#include <stdio.h>

main()
{
    short s;
    long l;
    int i;
    
    s = 1000;           /* عدد صغير */
    i = 50000;          /* عدد متوسط */
    l = 2000000000L;    /* عدد كبير، L في النهاية */
    
    printf("%d %d %ld\n", s, i, l);  /* %ld للأعداد الطويلة */
}
