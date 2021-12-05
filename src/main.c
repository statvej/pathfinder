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
    printf("%d\n", side_size);
    int namesLen = mx_get_lines_count(&lines[1]);
    char **trimed = mx_get_island_names(&lines[1], side_size, namesLen);
    // t_index_island *struct_arr = mx_gen_index_struct(trimed, side_size);
    // t_straight_len *arr_len = mx_get_straight_len_struct(&lines[1], namesLen);
    mx_print_strarr(trimed, "\n DELIM \n");
    // for (int count = 0; count < side_size; count++) {
    //     printf("ind struct = %s\n", struct_arr[count].island);
    // }
    // for (int count = 0; count < namesLen; count++) {
    //     printf("len struct start = %s\n", arr_len[count].start);
    //     printf("len struct dest = %s\n", arr_len[count].dest);
    // }
    //int **matrix = mx_create_matrix(struct_arr, arr_len, side_size, namesLen);
    

    //mx_print_matrix(matrix, side_size);
    

    free(data);
    free(lines);
}
