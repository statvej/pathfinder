#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    argc++;
    char *data = (char *)malloc(1024);
    char **lines = (char **)malloc(1024 * sizeof(char *));
    lines[1023] = NULL;
    int fd = open(argv[1], O_RDONLY);
    mx_read_line(&data, 1024, '\0', fd);
    close(fd);
    lines = mx_strsplit(data, '\n');
    int side_size = mx_read_island_count(data);
    char **trimed = mx_get_island_names(&lines[1], side_size);
    mx_print_strarr(trimed, "\n1");
    // t_index_island
    // int **matrix = mx_create_matrix(&lines[1], side_size);
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", trimed[i]);
    }
    // int namesLen = mx_get_lines_count(trimed);
    // //size_t pp = sizeof(lines) / sizeof(char *);
    // printf("%d\n", namesLen);
    //t_index_island *struct_arr = mx_gen_index_struct(trimed, side_size);
    // printf("%s\n", struct_arr[0].island);
    // mx_create_matrix(struct_arr, trimed, side_size);
    // t_straight_len * struct_len = mx_get_straight_len_struct(&lines[1]);
    free(data);
    free(lines);
}
//int argc, char **argv
