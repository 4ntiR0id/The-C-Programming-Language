/*
 * arrays_of_structures.c
 * 
 * An array can hold structures.
 * This organizes collections of related data.
 */

#include <stdio.h>

struct student {
    char name[30];
    int score;
};

main()
{
    struct student class[3];    /* مصفوفة من الهياكل */
    int i;
    
    class[0].score = 85;
    class[1].score = 90;
    class[2].score = 78;
    
    for (i = 0; i < 3; i++)
        printf("student %d: %d\n", i, class[i].score);
}
