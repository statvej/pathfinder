#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
void mx_print_matrix(int **matrix, int side_size)
{
    for (int i = 0; i < side_size; i++)
    {
        for (int c = 0; c < side_size; c++)
        {
            printf("%d ", matrix[i][c]);
        }
        printf(" \n");
    }
}
