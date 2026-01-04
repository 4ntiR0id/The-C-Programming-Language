/*
 * multidimensional_arrays.c
 * 
 * Multi-dimensional arrays are arrays of arrays.
 * Elements are stored in row-major order.
 */

#include <stdio.h>

main()
{
    int matrix[2][3] = {        /* مصفوفة 2×3 */
        {1, 2, 3},
        {4, 5, 6}
    };
    int i, j;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
