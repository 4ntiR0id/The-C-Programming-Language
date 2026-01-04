/*
 * bit_fields.c
 * 
 * Bit-fields allow packing data into individual bits.
 * They save space for flags and small integers.
 */

#include <stdio.h>

struct flags {
    unsigned int is_ready : 1;      /* بت واحد */
    unsigned int error : 1;
    unsigned int mode : 3;          /* 3 بتات */
};

main()
{
    struct flags f;
    
    f.is_ready = 1;                 /* 0 أو 1 فقط */
    f.error = 0;
    f.mode = 5;                     /* 0 إلى 7 */
    
    printf("%u %u %u\n", f.is_ready, f.error, f.mode);
}
