#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
void mx_print_matrix(int **matrix, int side_size) {
    for (int i = 0; i < side_size; i++) {
        for (int c = 0; c < side_size; c++) {
            printf("%d ", matrix[i][c]);
        }
        printf(" \n");
    }
}
void print_route_struct(t_route *arr_route, int elements) {
    for (int i = 0; i < elements; i++) {
        printf("START IS %d\nDEST IS %d\nCOUNT IS %d\n", arr_route[i].start, arr_route[i].dest, arr_route[i].links_count);
        if (arr_route[i].list[0] != -1) {
                printf("ROUTE GOES THROUGH ");
            for (int z = 0; arr_route[i].list[z] != -1; z++) {
                printf("%d  ", arr_route[i].list[z]);
            }
            printf("\n\n");
        } else {
            printf("PATH is STRAIGHT\n\n");
        }
    }
}
