/*
 * relational_operators.c
 * 
 * Relational operators compare two values.
 * They return 1 for true and 0 for false.
 */

#include <stdio.h>

main()
{
    int a = 5, b = 10;
    
    printf("%d\n", a < b);   /* أصغر من: 1 */
    printf("%d\n", a > b);   /* أكبر من: 0 */
    printf("%d\n", a <= b);  /* أصغر أو يساوي: 1 */
    printf("%d\n", a >= b);  /* أكبر أو يساوي: 0 */
    printf("%d\n", a == b);  /* يساوي: 0 */
    printf("%d\n", a != b);  /* لا يساوي: 1 */
}
