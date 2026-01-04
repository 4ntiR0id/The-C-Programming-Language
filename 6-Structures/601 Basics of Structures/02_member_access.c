/*
 * member_access.c
 * 
 * Structure members are accessed using the dot operator.
 * Each member has its own storage.
 */

#include <stdio.h>

struct person {
    char name[50];
    int age;
    float height;
};

main()
{
    struct person p;
    
    p.age = 25;                     /* إسناد لعضو */
    p.height = 5.9;
    
    printf("age: %d\n", p.age);
    printf("height: %.1f\n", p.height);
}
