#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    argc++;
    char *data = (char *)malloc(1024);
    char**lines= (char **)malloc(1024);
    int fd = open(argv[1], O_RDONLY);
    mx_read_line(&data, 1024, '\0', fd);
    close(fd);
    lines = mx_strsplit(data, '\n');
    int side_size = mx_read_island_count(data);
    // char **trimed = (char**)malloc(side_size*(sizeof(char) * 100 + 1));
    // for (int count = 0; count < side_size; count++)
    // {
    //     trimed[count] = (char *)malloc(sizeof(char) * 100 + 1);
    // }
    //int matrix[c][c] = mx_create_matrix(&lines[1], c);
    mx_printstr("test\n");
    mx_print_strarr(lines, "\0");
    char **trimed = mx_get_island_names(&lines[1], side_size);
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", trimed[i]);
    }
  
    //printf("%s\n%d", trimed[1], side_size);
    free(data);
    free(lines);
}
//int argc, char **argv
