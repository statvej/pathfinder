#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    mx_check_args(argc);
    char *data = (char *)malloc(1024);
    char **lines = (char **)malloc(1024 * sizeof(char *));
    lines[1023] = NULL;
    int fd = open(argv[1], O_RDONLY);
    mx_read_line(&data, 1024, '\0', fd);
    close(fd);
    lines = mx_strsplit(data, '\n');
    int side_size = mx_read_island_count(data);
    printf("%d\n", side_size);
    int namesLen = mx_get_lines_count(&lines[1]);
    char **trimed = mx_get_island_names(&lines[1], side_size, namesLen);
    t_index_island *struct_arr = mx_gen_index_struct(trimed, side_size);
    t_straight_len *arr_len = mx_get_straight_len_struct(&lines[1], namesLen);
    int **matrix = mx_create_matrix(struct_arr, arr_len, side_size, namesLen);
    // for (int count = 0; count < side_size; count++)
    // {
    //     printf("%s\n%d\n", struct_arr[count].island, struct_arr[count].index);
    // }
    for (int count = 0; count < namesLen; count++)
    {
        printf("%s\n%s\n%d\n", arr_len[count].start, arr_len[count].dest, arr_len[count].len);
    }
    printf("%d\n", matrix[0][0]);
    mx_print_matrix(matrix, side_size);
    // printf("%s\n%s\n%d\n",arr_len[1].start, arr_len[1].dest, arr_len[1].len);

    free(data);
    free(lines);
}
