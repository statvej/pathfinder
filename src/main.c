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
    int namesLen = mx_get_lines_count(&lines[1]);
    char **trimed = mx_get_island_names(&lines[1], side_size, namesLen);
    t_straight_len*pp = mx_get_straight_len_struct(&lines[1], namesLen);
    printf("%s\n%s\n%d\n",pp[1].start, pp[1].dest, pp[1].len);
    mx_print_strarr(trimed, "\nZZ");
    free(data);
    free(lines);
}
