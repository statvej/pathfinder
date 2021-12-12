#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
int mx_read_island_count(char *data) {

    int res = 0;
    int del = mx_get_char_index((const char *)data, '\n');
    char *temp = (char *)malloc(10 * sizeof(char));
    for (int count = 0; count <= del; count++) {
        temp[count] = data[count];
    }

    res = mx_atoi((const char *)temp);
    free((void *)temp);
    return res;
}
