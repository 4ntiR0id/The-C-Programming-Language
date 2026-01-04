/*
 * data_type_float.c
 * 
 * A float holds a floating-point number.
 * Use it for numbers with decimal points.
 */

#include <stdio.h>

main()
{
    float temperature;
    float price;
    
    temperature = 98.6;     /* عدد عشري */
    price = 19.99;
    
    printf("%f\n", temperature);    /* %f للأعداد العشرية */
    printf("%.2f\n", price);        /* رقمان بعد الفاصلة */
}
