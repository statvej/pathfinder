#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

t_route *mx_algorithm(t_route *struct_route, int **matrix, int side_size) {

    for (int stage = 0; stage < side_size; stage++) {
        for (int start = 0; start < side_size; start++) {
            for (int dest = 0; dest < side_size; dest++) {
                if (matrix[start][stage] + matrix[stage][dest] < matrix[start][dest])
                    matrix[start][dest] = matrix[start][stage] + matrix[stage][dest];
            }
        }
    }
    mx_print_matrix(matrix, side_size);
    return struct_route;
}
