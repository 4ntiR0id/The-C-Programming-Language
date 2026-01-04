/*
 * callbacks.c
 * 
 * Function pointers enable callbacks.
 * A function can call back to code provided by the caller.
 */

#include <stdio.h>

void process_array(int arr[], int n, void (*callback)(int));
void print_value(int x);
void print_double(int x);

main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    
    process_array(numbers, 5, print_value);
    printf("\n");
    process_array(numbers, 5, print_double);
}

void process_array(int arr[], int n, void (*callback)(int))
{
    int i;
    for (i = 0; i < n; i++)
        (*callback)(arr[i]);            /* استدعاء الدالة المعطاة */
}

void print_value(int x)
{
    printf("%d ", x);
}

void print_double(int x)
{
    printf("%d ", x * 2);
}
