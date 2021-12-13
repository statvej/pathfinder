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
int mx_get_lines_count(char **text) {
    if (!text) {
        return 0;
    }
    int count = 0;
    for (; text[count] != NULL; count++) {
    }
    return count;
}
int mx_atoi(const char *str) {
    if (!str)
        return 0;

    char *temp = mx_unconstchar(str);
    int res = 0;
    int count = mx_strlen(temp);
    for (int i = 0; i <= count && mx_isdigit(str[i]); i++) {
        res = res * 10 + (str[i] - 48);
    }

    return res;
}
int mx_check_dupl(char **check, char *sub) {
    for (int i = 0; check[i] != NULL; i++) {

        if (mx_strcmp(check[i], sub) == 0) {

            return 0;
        }
    }
    return 1;
}

