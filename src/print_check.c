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
        printf(
            "START IS %d\nDEST IS %d\nCOUNT IS %d\n", arr_route[i].start, arr_route[i].dest, arr_route[i].links_count);
        if (arr_route[i].list[0] != -1) {
            printf("ROUTE GOES THROUGH ");
            for (int z = 0; arr_route[i].list[z] != -1; z++) {
                printf("%d  ", arr_route[i].list[z]);
            }
            printf("\n\n");
        }
        else {
            printf("PATH is STRAIGHT\n\n");
        }
    }
}
void print_index_struct(t_index_island *struct_index, int elem_num) {
    for (int i = 0; i < elem_num; i++) {
        printf("ISLAND NAME IS %s\nITS INDEX = %d\n", struct_index[i].island, struct_index[i].index);
    }
}
void print_len_struct(t_straight_len * arr_len, int namesLen) {
    for (int count = 0; count < namesLen; count++) {
        printf("len struct start = %s\n", arr_len[count].start);
        printf("len struct dest = %s\nlen struct len = %d\n", arr_len[count].dest, arr_len[count].len);
    }
}