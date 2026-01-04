/*
 * return_values.c
 * 
 * Functions communicate results through return values.
 * A function without return returns to the caller with no value.
 */

#include <stdio.h>

int add(int a, int b);
void print_sum(int a, int b);   /* void تعني لا قيمة مرجعة */

main()
{
    int x;
    
    x = add(5, 3);              /* استقبال القيمة المرجعة */
    printf("%d\n", x);
    
    print_sum(5, 3);            /* لا قيمة مرجعة */
}

int add(int a, int b)
{
    return a + b;               /* إرجاع القيمة */
}

void print_sum(int a, int b)
{
    printf("%d\n", a + b);      /* لا return ضروري */
}
