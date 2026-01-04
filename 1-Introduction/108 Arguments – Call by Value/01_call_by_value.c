/*
 * call_by_value.c
 * 
 * In C, function arguments are passed by value.
 * The function receives a copy, not the original variable.
 */

#include <stdio.h>

int power(int base, int n);

main()
{
    int x;
    
    x = 3;
    printf("%d\n", power(x, 4));
    printf("%d\n", x);  /* x لم تتغير */
}

int power(int base, int n)
{
    int p;
    
    p = 1;
    while (n > 0) {
        p = p * base;
        n--;  /* تغيير n هنا لا يؤثر على المتغير الأصلي */
    }
    return p;
}
