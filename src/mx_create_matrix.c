#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

int **init_matrix(int side_size) {
    int **matrix = (int **)malloc(sizeof(int *) * side_size);
    for (int i = 0; i < side_size; i++) {
        matrix[i] = (int *)malloc(side_size * sizeof(int));
        for (int c = 0; c < side_size; c++) {
            matrix[i][c] = INT_MAX;
        }
        matrix[i][i] = 0;
    }
    return matrix;
}

int **mx_create_matrix(t_index_island *struct_arr, t_straight_len *arr_len, int side_size, int names_len) {
    int **matrix = init_matrix(side_size);
    for (int count = 0; count < names_len; count++) {
        int check = 0;
        char *start = mx_strndup(arr_len[count].start, mx_strlen(arr_len[count].start));
        char *dest = mx_strndup(arr_len[count].dest, mx_strlen(arr_len[count].dest));
        int ind_s = -1;
        int ind_d = -1;
        for (int count2 = 0; count2 < side_size && check <= 0; count2++) {

            if (mx_strcmp(struct_arr[count2].island, start) == 0) {
                ind_s = struct_arr[count2].index;
            }
            if (mx_strcmp(struct_arr[count2].island, dest) == 0) {
                ind_d = struct_arr[count2].index;
            }
            if (ind_d != -1 && ind_s != -1) {
                matrix[ind_s][ind_d] = arr_len[count].len;
                matrix[ind_d][ind_s] = arr_len[count].len;
                check++;
            }
        }
        free((void *)start);
        free((void *)dest);
    }
    return matrix;
}
