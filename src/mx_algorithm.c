#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>

t_route *mx_algorithm(t_route *struct_route, int **matrix, int side_size, t_ind_len *ind_len, int namesLen) {
    int route_count = (side_size * (side_size - 1)) / 2;
    for (int stage = side_size - 1; stage >= 0; stage--) {

        for (int start = 0; start < side_size; start++) {

            for (int dest = 0; dest < side_size; dest++) {

                if (matrix[start][stage] + matrix[stage][dest] == matrix[start][dest]) {
                }
                if (matrix[start][stage] + matrix[stage][dest] < matrix[start][dest] &&
                    matrix[start][stage] + matrix[stage][dest] >= 0 && matrix[start][stage] + matrix[stage][dest] > 0) {
                    for (int save_count = 0; save_count < side_size * (side_size - 1) / 2;
                         save_count++) { /*Добавление данных в структуру по
                                         которой пойдет печать*/
                        if (struct_route[save_count].start == start && struct_route[save_count].dest == dest) {
                            struct_route[save_count].list[0] = stage;
                        }
                    }
                    matrix[start][dest] = matrix[start][stage] + matrix[stage][dest];
                }
            }
        }
    }
    mx_print_matrix(matrix, side_size);
    //struct_route = mx_multi_path_detector(matrix, struct_route, side_size, &route_count);
    struct_route = temp_path_completion(struct_route, side_size);
    struct_route = post_algorithm_processing(struct_route, side_size, ind_len, namesLen);
    print_route_struct(struct_route, route_count);
    // mx_print_matrix(matrix, side_size);

    return struct_route;
}

t_route *mx_insert_route(int *route_count, t_route *route, int stage, int start, int dest, int side_size) {
    int new_size = (*route_count) + 1;
    int index_new = get_index_from_route_struct(start, dest, *route_count, route) + 1;
    print_int_err(new_size);
    t_route *ret = malloc(sizeof(t_route) * new_size);
    int count1 = 0;
    for (; count1 < index_new; count1++) {
        ret[count1].dest = route[count1].dest;
        ret[count1].start = route[count1].start;
        ret[count1].list = mx_copy_route_list(route[count1].list, side_size);
    }
    int grand_count = count1 + 1;
    ret[grand_count].dest = dest;
    ret[grand_count].start = start;
    ret[grand_count].list = (int *)malloc(sizeof(int) * side_size);
    for (int i = 0; i < side_size; i++) {
        ret[grand_count].list[i] = -1;
    }
    ret[grand_count].list[0] = start;
    ret[grand_count].list[1] = stage;
    ret[grand_count].list[2] = dest;
    for (; count1 < index_new; count1++) {
        ret[grand_count].dest = route[count1].dest;
        ret[grand_count].start = route[count1].start;
        ret[grand_count].list = mx_copy_route_list(route[count1].list, side_size);
    }

    mx_free_route(route, *route_count);
    *route_count++;
    return ret;
}

t_route *mx_multi_path_detector(int **matrix, t_route *route, int side_size, int *route_count) {

    for (int stage = side_size - 1; stage >= 0; stage--) {

        for (int start = 0; start < side_size; start++) {

            for (int dest = 0; dest < side_size; dest++) {

                if (matrix[start][stage] + matrix[stage][dest] == matrix[start][dest]) {
                    mx_insert_route( route_count, route, stage, start, dest, side_size);
                }
            }
        }
    }
}

t_route *temp_path_completion(t_route *route, int side_size) { // Ads to list of islands start and dest points
    int path_num = side_size * (side_size - 1) / 2;
    for (int i = 0; i < path_num; i++) {

        int arr_size = get_index_route(route[i].list) + 2;
        int *path = (int *)malloc(sizeof(int) * arr_size);
        path[0] = route[i].start;
        for (int count1 = 1; count1 < arr_size - 1; count1++) {
            path[count1] = route[i].list[count1 - 1];
        }
        path[arr_size - 1] = route[i].dest;

        for (int count2 = 0; count2 < arr_size; count2++) { // Rewrite of data
            route[i].list[count2] = path[count2];
        }
        free(path);
    }
    return route;
}

// Checks if global route is correct
int check_optimal_route(t_route checked, int **matrix, t_ind_len *ind_len, int namesLen) {

    int arr_size = get_index_route(checked.list); // preparation before check
    int sum = 0;
    int need_sum = matrix[checked.start][checked.dest];
    int sub_path = 0;
    for (int count = 0; count < arr_size - 1; count++) { // Calculating sum
        sub_path = 0;
        int ind_s = checked.list[count];
        int ind_d = checked.list[count + 1];
        for (int count2 = 0; count2 < namesLen; count2++) {
            if (ind_s == ind_len[count2].start && ind_d == ind_len[count2].dest) {
                sub_path = ind_len[count2].len;
            }
            if (ind_d == ind_len[count2].start && ind_s == ind_len[count2].dest) {
                sub_path = ind_len[count2].len;
            }
        }
        sum += sub_path;
    }
    if (sum == need_sum) {
        return 1;
    }
    return 0;
}

int is_path_straight(int start, int dest, int namesLen, t_ind_len *ind_len) {
    for (int i = 0; i < namesLen; i++) {
        if (ind_len[i].start == start && ind_len[i].dest == dest) {
            return 1;
        }
        if (ind_len[i].start == dest && ind_len[i].dest == start) {
            return 1;
        }
    }
    return 0;
}

int get_index_from_route_struct(int start, int dest, int path_num, t_route *route) {
    for (int i = 0; i < path_num; i++) {
        if (start == route[i].start && dest == route[i].dest) {
            for (; start == route[i].start && dest == route[i].dest; i++) {
            }
            return i;
        }
        else if (dest == route[i].start && start == route[i].dest) {
            for (; dest == route[i].start && start == route[i].dest; i++) {
            }
            return i;
        }
    }
    return -1;
}

int get_num_index_in_arr(int num, int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (num == arr[i]) {
            return i;
        }
    }
    return -1;
}

int *conect_routes(int *main, int *sub, int start, int dest, int side_size) {

    int sub_size = get_index_route(sub);
    int *temp_arr = (int *)malloc(sizeof(int) * side_size);
    int pre_count, rewr_count, post_count, grand_count;
    grand_count = 0;
    int ind_s = get_num_index_in_arr(start, main, side_size);
    int ind_d = get_num_index_in_arr(dest, main, side_size);
    for (int i = 0; i < side_size; i++) { // Preparetionn of temporary array for rewriting
        temp_arr[i] = -1;
    }
    if (sub[0] != start &&
        sub[sub_size - 1] != dest) { // if sub route hos reversed destinstion and start we need to reverse it
        sub = reverse_route(sub, sub_size);
    }

    for (pre_count = 0; pre_count < ind_s; pre_count++) { // temp_arr to full route
        temp_arr[grand_count] = main[pre_count];
        grand_count++;
    }
    for (rewr_count = 0; rewr_count < sub_size; rewr_count++) {
        temp_arr[grand_count] = sub[rewr_count];
        grand_count++;
    }
    for (post_count = ind_d + 1; main[post_count] != -1; post_count++) {
        temp_arr[grand_count] = main[post_count];
        grand_count++;
    }

    for (grand_count = 0; temp_arr[grand_count] != -1; grand_count++) { // final rewrite
        main[grand_count] = temp_arr[grand_count];
    }

    free(temp_arr);
    return main;
}

t_route *post_algorithm_processing(t_route *struct_route, int side_size, t_ind_len *ind_len, int namesLen) {
    int path_num = side_size * (side_size - 1) / 2;
    for (int count1 = 0; count1 < path_num; count1++) {
        /* Going through all the destinations*/
        for (int count2 = 0; count2 < get_index_route(struct_route[count1].list) - 1;
             count2++) { // Probably should be changed to "-1", instead of "-2"
            int temp_start = struct_route[count1].list[count2];
            int temp_dest = struct_route[count1].list[count2 + 1];
            if (is_path_straight(temp_start, temp_dest, namesLen, ind_len) == false) {
                int temp_ind = get_index_from_route_struct(temp_start, temp_dest, path_num, struct_route);

                struct_route[count1].list = conect_routes(
                    struct_route[count1].list, struct_route[temp_ind].list, temp_start, temp_dest, side_size);
            }
        }
    }
    for (int count1 = 0; count1 < path_num; count1++) {
        int value_size = get_index_route(struct_route[count1].list);
        if (struct_route[count1].start != struct_route[count1].list[0]) {
            struct_route[count1].list = reverse_route(struct_route[count1].list, value_size);
        }
    }
    return struct_route;
}
