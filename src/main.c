#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
int main(int argc, char **argv) {
    mx_check_args(argc);
    char *data;

    int fd = open(argv[1], O_RDONLY);
    mx_read_line(&data, INT_MAX, '\0', fd);
    close(fd);
    char **lines = mx_strsplit(data, '\n');
    int side_size = mx_read_island_count(data);
    int namesLen = mx_get_lines_count(&lines[1]);
    char **trimed = mx_get_island_names(&lines[1], side_size, namesLen);
    t_index_island *struct_arr = mx_gen_index_struct(trimed, side_size);
    t_straight_len *arr_len = mx_get_straight_len_struct(&lines[1], namesLen);
    t_ind_len * ind_len = make_ind_len_struct(struct_arr, arr_len, namesLen, side_size);
    print_ind_len_struct(ind_len, namesLen);
    print_index_struct(struct_arr, side_size);
    print_len_struct(arr_len, namesLen);
    int **matrix = mx_create_matrix(struct_arr, arr_len, side_size, namesLen);
    mx_print_matrix(matrix, side_size);
    t_route *route_arr = mx_init_route_struct(side_size);
    printf("\n\t DELIM!!!\n\n");
    route_arr = mx_algorithm(route_arr, matrix, side_size);

    mx_free_route(route_arr);
    free(data);
    free(lines);
}
