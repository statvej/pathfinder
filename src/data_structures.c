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

t_index_island *mx_gen_index_struct(char **trimed, int side_size) {
    t_index_island *ret = (t_index_island *)malloc(sizeof(t_index_island) * side_size);

    for (int count = 0; count < side_size; count++) {
        ret[count].index = count;
        ret[count].island = (char *)malloc(sizeof(char) * mx_strlen(trimed[count]));
        ret[count].island = trimed[count];
    }
    return ret;
}

char **mx_get_island_names(char **untrimed, int side_size, int line_count) {
    char **trim = malloc(side_size * sizeof(char *));
    char **ret = trim;
    char **arr_temp = NULL;
    char **arr_temp_sub = NULL;
    for (int count1 = 0; count1 != line_count; count1++) {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        if (mx_check_dupl(ret, arr_temp[0]) == 1) {
            *trim = mx_strndup(arr_temp[0], mx_strlen(arr_temp[0]));
            trim++;
        }
        arr_temp_sub = mx_strsplit(arr_temp[1], ',');
        if (mx_check_dupl(ret, arr_temp_sub[0]) == 1) {
            *trim = mx_strndup(arr_temp_sub[0], mx_strlen(arr_temp_sub[0]));
            trim++;
        }
        free(arr_temp);
        free(arr_temp_sub);
    }
    
    return ret;
}
t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count) {
    t_straight_len *ret = (t_straight_len *)malloc(sizeof(t_straight_len) * (line_count));
    int count1 = 0;
    char **arr_temp = NULL;
    char **arr_temp_sub = NULL;
    for (; count1 < line_count; count1++) {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        arr_temp_sub = mx_strsplit(arr_temp[1], ',');
        (ret + count1)->start = mx_strndup(arr_temp[0], mx_strlen(arr_temp[0]));
        (ret + count1)->dest = mx_strndup(arr_temp_sub[0], mx_strlen(arr_temp_sub[0]));
        (ret + count1)->len = mx_atoi(arr_temp_sub[1]);
        free((void *)arr_temp);
        free((void *)arr_temp_sub);
    }
    return ret;
}
t_route *mx_init_route_struct(int side_size) {
    t_route *ret = (t_route *)malloc((side_size * (side_size - 1)) / 2 * sizeof(t_route));
    int grand_count = 0;
    for (int count1 = 0; count1 < side_size; count1++) {
        for (int count2 = 1; count2 + count1 < side_size; count2++) {
            ret[grand_count].start = count1;
            ret[grand_count].dest = count2 + count1;
            ret[grand_count].list = (int *)malloc(sizeof(int) * side_size);
            for (int i = 0; i < side_size; i++) {
                ret[grand_count].list[i] = -1;
                // printf("\t\t%d\n", ret[grand_count].list[i]);
            }
            grand_count++;
        }
        if (grand_count >= (side_size * (side_size - 1)) / 2) {
            return ret;
        }
    }
    // print_route_struct(ret, 10);
    return ret;
}
t_ind_len *make_ind_len_struct(t_index_island *struct_arr, t_straight_len *arr_len, int namesLen, int side_size) {
    t_ind_len *ret = (t_ind_len *)malloc(sizeof(t_ind_len) * namesLen);
    for (int count = 0; count < namesLen; count++) {
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
                ret[count].start = ind_s;
                ret[count].dest = ind_d;
                ret[count].len = arr_len[count].len;
                check++;
            }
        }
        free((void *)start);
        free((void *)dest);
    }
    return ret;
}
