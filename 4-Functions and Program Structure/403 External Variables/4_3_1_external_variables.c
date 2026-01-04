/*
 * external_variables.c
 * 
 * External variables are shared among all functions.
 * They provide a way to communicate data without arguments.
 */

#include <stdio.h>

int counter = 0;                /* متغير خارجي */

void increment(void);
void print_counter(void);

main()
{
    increment();
    increment();
    print_counter();
}

void increment(void)
{
    counter++;                  /* الوصول للمتغير الخارجي */
}

void print_counter(void)
{
    printf("%d\n", counter);    /* كل الدوال ترى counter */
}
