#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

t_route *mx_algorithm(t_route *struct_route, int **matrix, int side_size, t_ind_len *ind_len, int namesLen) {
    for (int stage = 0; stage < side_size; stage++) {

        for (int start = 0; start < side_size; start++) {

            for (int dest = 0; dest < side_size; dest++) {

                if (matrix[start][stage] + matrix[stage][dest] < matrix[start][dest] &&
                    matrix[start][stage] + matrix[stage][dest] >= 0) {

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
    print_route_struct(struct_route, side_size * (side_size - 1) / 2);
    mx_print_matrix(matrix, side_size);
    mx_free_matrix(matrix, side_size);

    return struct_route;
}

int check_optimal_route(t_route checked, int **matrix, t_ind_len *ind_len, int side_size, int namesLen) {

    int arr_size = get_index_route(checked.list) + 2; // preparation before check
    int *path = (int *)malloc(sizeof(int) * arr_size);
    path[0] = checked.start;
    for (int i = 1; i < arr_size - 1; i++) {
        path[i] = checked.list[i - 1];
    }
    path[arr_size - 1] = checked.dest;
    int sum = 0;
    int need_sum = matrix[checked.start][checked.dest];
    int sub_path = 0;

    for (int count = 0; count < arr_size - 1; count++) { // Calculating sum
        sub_path = 0;
        int ind_s = path[count];
        int ind_d = path[count + 1];
        for (int count2 = 0; count2 < namesLen; count2++) {
            if (ind_s == ind_len[count2].start && ind_d == ind_len[count2].dest) {
                sub_path = ind_len[count2].len;
            }
        }
        sum += sub_path;
    }
    if (sum == need_sum) {
        return 1;
    }

    free(path);

    return 0;
}

// t_route *post_algorithm_processing(t_route *struct_route, int side_size) {
//     int path_num = side_size * (side_size - 1) / 2;
//     for (int i = 0; i < path_num; i++) {
//         if (struct_route[i].list[0] != -1) {
//             int border = get_index_route(struct_route[i].list);

//         }
//     }
//     return struct_route;
// }
