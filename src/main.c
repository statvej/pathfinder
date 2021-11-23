#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    argc++;
    char *data = (char *)malloc(1024);
    char**lines= (char **)malloc(1024*sizeof(char*));
    int fd = open(argv[1], O_RDONLY);
    mx_read_line(&data, 1024, '\0', fd);
    close(fd);
    lines = mx_strsplit(data, '\n');
    int side_size = mx_read_island_count(data);
    char **trimed = mx_get_island_names(&lines[1], side_size);
    t_index_island
    // int **matrix = mx_create_matrix(&lines[1], side_size);
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", trimed[i]);
    }
  matrix++;
    
    free(data);
    free(lines);
}
//int argc, char **argv
