/*
 * bitwise_operators.c
 * 
 * Bitwise operators work on individual bits.
 * They are useful for low-level operations.
 */

#include <stdio.h>

main()
{
    unsigned int a = 12;    /* 1100 في النظام الثنائي */
    unsigned int b = 10;    /* 1010 في النظام الثنائي */
    
    printf("%u\n", a & b);  /* AND: 8 (1000) */
    printf("%u\n", a | b);  /* OR: 14 (1110) */
    printf("%u\n", a ^ b);  /* XOR: 6 (0110) */
    printf("%u\n", ~a);     /* NOT: يعكس كل البتات */
    printf("%u\n", a << 1); /* إزاحة لليسار: 24 (11000) */
    printf("%u\n", a >> 1); /* إزاحة لليمين: 6 (110) */
}
