/*
 * integer_constants.c
 * 
 * Integer constants can be written in decimal, octal, or hexadecimal.
 * The form determines how the compiler reads the number.
 */

#include <stdio.h>

main()
{
    int dec, oct, hex;
    
    dec = 100;      /* عدد عشري عادي */
    oct = 0144;     /* يبدأ بـ 0 يعني ثماني */
    hex = 0x64;     /* يبدأ بـ 0x يعني ستة عشري */
    
    printf("%d %d %d\n", dec, oct, hex);  /* كلها تساوي 100 */
}
