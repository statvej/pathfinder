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
                    for (int sub = 0; sub < 1; sub++) {
                        for (int save_count = 0; save_count < side_size * (side_size - 1) / 2; save_count++) { //Добавление данных в структуру по которой пойдет печать
                            if (struct_route[save_count].start == start && struct_route[save_count].dest == dest) {
                                printf("\tSTAGE BREAK ON %d\n\n", stage);
                                struct_route[save_count].list[struct_route[save_count].links_count] = stage;
                                struct_route[save_count].links_count++;
                            }
                        }
                    }
                    printf("STAGE BREAK ON %d\n\n", stage);
                    matrix[start][dest] = matrix[start][stage] + matrix[stage][dest];
                }
            }
        }
    }
    // printf("STAGE ID = %d\n", struct_route[1].list[1]);
    print_route_struct(struct_route, 10);
    mx_print_matrix(matrix, side_size);
    return struct_route;
}
