#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

t_route *mx_algorithm(t_route *struct_route, int **matrix, int side_size) {
    for (int stage = 0; stage < side_size; stage++) {

        for (int start = 0; start < side_size; start++) {

            for (int dest = 0; dest < side_size; dest++) {

                if (matrix[start][stage] + matrix[stage][dest] < matrix[start][dest] &&
                    stage != start && stage != dest &&
                    matrix[start][stage] + matrix[stage][dest] >= 0) {

                    for (int save_count = 0; save_count < side_size * (side_size - 1) / 2;
                         save_count++) { /*Добавление данных в структуру по
                                         которой пойдет печать*/
                        if (struct_route[save_count].start == start && struct_route[save_count].dest == dest) {

                            int temp_lis_index = get_index_route(struct_route[save_count].list);
                            struct_route[save_count].list[temp_lis_index] = stage;
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

int get_index_route(int *list) {
    int res = 0;
    while (list[res] != -1) {
        res++;
    }

    return res;
}

// t_route *post_algorithm_processing(t_route *struct_route, int side_size) {

//     for (int i = 0; i < side_size * (side_size - 1) / 2; i++) {
//         if (struct_route[i].list[0] != -1) {
//             int border = get_index_route(struct_route[i].list);

//         }
//     }
//     return struct_route;
// }
