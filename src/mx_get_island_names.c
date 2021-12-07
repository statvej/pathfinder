#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

int mx_check_dupl(char **check, char *sub) {
    for (int i = 0; check[i] != NULL; i++) {

        if (mx_strcmp(check[i], sub) == 0) {

            return 0;
        }
    }
    return 1;
}

char **mx_get_island_names(char **untrimed, int side_size, int line_count) {
    char **trim = malloc(side_size * sizeof(char *));
    char **ret = trim;
    char **arr_temp = NULL;
    char **arr_temp_sub = NULL;
    for (int count1 = 0; count1 != line_count; count1++) {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        if (mx_check_dupl(ret, arr_temp[0]) == 1) {
            *trim = mx_strndup(arr_temp[0], mx_strlen(arr_temp[0]));
            trim++;
        }
        arr_temp_sub = mx_strsplit(arr_temp[1], ',');
        if (mx_check_dupl(ret, arr_temp_sub[0]) == 1) {
            *trim = mx_strndup(arr_temp_sub[0], mx_strlen(arr_temp_sub[0]));
            trim++;
        }
        free(arr_temp);
        free(arr_temp_sub);
    }
    *trim = NULL;
    return ret;
}
