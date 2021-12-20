#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

void mx_free_matrix(void **ptr, int len) {
    for (int i = 0; i < len; i++) {
        free(ptr[i]);
    }
    free(ptr);
}
void mx_free_route(t_route *route, int side_size) {
    int path_num = side_size * (side_size - 1) / 2;
    for (int i = 0; i < path_num; i++) {
        free(route[i].list);
    }
    free(route);
}

void mx_free_strght_len_struct(t_straight_len *straight_len, int namesLen) {
    for (int count = 0; count < namesLen; count++) {
        free(straight_len[count].start);
        free(straight_len[count].dest);
    }
    free(straight_len);
}

void mx_free_ind_len(t_ind_len *ind_len) {
    free(ind_len);
}
void mx_free_ind_isl(t_index_island *ind_isl, int side_size) {
    for (int count = 0; count < side_size; count++) {
        free(ind_isl[count].island);
    }
    free(ind_isl);
}
