#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
void mx_print_matrix(int **matrix, int side_size) {
    fprintf(stderr, "\n\n\tMATRIX AHEAD :)\n");
    for (int i = 0; i < side_size; i++) {
        for (int c = 0; c < side_size; c++) {
            fprintf(stderr, "%d ", matrix[i][c]);
        }
        fprintf(stderr, " \n");
    }
}
void print_route_struct(t_route *arr_route, int elements) {
    fprintf(stderr, "\n\n\tROUTE STRUCT :\n");
    for (int i = 0; i < elements; i++) {
        fprintf(stderr, "START IS %d\nDEST IS %d\n", arr_route[i].start, arr_route[i].dest);
        if (arr_route[i].list[0] != -1) {
            fprintf(stderr, "ROUTE GOES THROUGH ");
            for (int z = 0; arr_route[i].list[z] != -1; z++) {
                fprintf(stderr, "%d  ", arr_route[i].list[z]);
            }
            fprintf(stderr, "\n\n");
        }
        else {
            fprintf(stderr, "PATH is STRAIGHT\n\n");
        }
    }
}
void print_index_struct(t_index_island *struct_index, int elem_num) {
    fprintf(stderr, "\n\n\tINDEX STRUCT :\n");
    for (int i = 0; i < elem_num; i++) {
        fprintf(stderr, "ISLAND NAME IS %s\nITS INDEX = %d\n", struct_index[i].island, struct_index[i].index);
    }
}
void print_len_struct(t_straight_len *arr_len, int namesLen) {
    fprintf(stderr, "\n\n\tSTRAIGHT LEN STRUCT :\n");
    for (int count = 0; count < namesLen; count++) {
        fprintf(stderr, "len struct start = %s\n", arr_len[count].start);
        fprintf(stderr, "len struct dest = %s\nlen struct len = %d\n", arr_len[count].dest, arr_len[count].len);
    }
}
void print_ind_len_struct(t_ind_len *arr_len, int namesLen) {
    fprintf(stderr, "\n\n\tIND LEN STRUCT :\n");
    for (int count = 0; count < namesLen; count++) {
        fprintf(stderr, "len struct start = %d\n", arr_len[count].start);
        fprintf(stderr, "len struct dest = %d\nlen struct len = %d\n", arr_len[count].dest, arr_len[count].len);
    }
}
void print_single_route_struct(t_route route) {
    fprintf(stderr, "\n\n\tROUTE STRUCT :\n");

    fprintf(stderr, "START IS %d\nDEST IS %d\n", route.start, route.dest);
    if (route.list[0] != -1) {
        fprintf(stderr, "ROUTE GOES THROUGH ");
        for (int z = 0; route.list[z] != -1; z++) {
            fprintf(stderr, "%d  ", route.list[z]);
        }
        fprintf(stderr, "\n\n");
    }
    else {
        fprintf(stderr, "PATH is STRAIGHT\n\n");
    }
}
void conect_routes_print_check(int *main, int *sub, int start, int dest, int side_size) {
    fprintf(stderr, "\n\tCONNECT ROUTES CHECK :\n\nMAIN : ");
    for (int i = 0; i < side_size; i++) {
        fprintf(stderr, "%d ", main[i]);
    }

    fprintf(stderr, "\nSUB : ");

    for (int i = 0; i < side_size; i++) {
        fprintf(stderr, "%d ", sub[i]);
    }
    fprintf(stderr, "\nSTART IS %d\nDEST IS %d\nSIDE SIZE IS %d\n", start, dest, side_size);
}
