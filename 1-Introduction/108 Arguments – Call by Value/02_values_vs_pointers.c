/*
 * values_vs_pointers.c
 * 
 * To modify a variable in the caller, pass its address.
 * Arrays are passed as addresses, not copies.
 */

#include <stdio.h>

void increment(int x);  /* يستقبل نسخة */
void fill_array(int arr[], int n);  /* يستقبل عنوان */

main()
{
    int value;
    int list[5];
    int i;
    
    value = 10;
    increment(value);
    printf("%d\n", value);  /* لم تتغير */
    
    fill_array(list, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", list[i]);  /* تغيرت */
    printf("\n");
}

void increment(int x)
{
    x = x + 1;  /* يغير النسخة فقط */
}

void fill_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = i;  /* يغير المصفوفة الأصلية */
}
