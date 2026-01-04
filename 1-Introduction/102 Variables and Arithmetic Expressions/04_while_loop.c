/*
 * while_loop.c
 * 
 * The while statement repeats a group of statements as long as a condition is true.
 * This is the temperature conversion table from the book.
 */

#include <stdio.h>

main()
{
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    while (fahr <= upper) {  /* كرر طالما fahr أصغر من أو يساوي upper */
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;  /* زد قيمة fahr */
    }
}
