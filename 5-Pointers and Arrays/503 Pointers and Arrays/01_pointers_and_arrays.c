/*
 * pointers_and_arrays.c
 * 
 * An array name is a pointer to its first element.
 * Array indexing is pointer arithmetic.
 */

#include <stdio.h>

main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    
    p = a;                      /* a هو عنوان العنصر الأول */
    
    printf("%d\n", a[0]);       /* الطريقة العادية */
    printf("%d\n", *p);         /* نفس الشيء باستخدام المؤشر */
    
    printf("%d\n", a[2]);       /* العنصر الثالث */
    printf("%d\n", *(p + 2));   /* نفس الشيء */
}
