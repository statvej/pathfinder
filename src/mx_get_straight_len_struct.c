#include "patfinder.h"
#include "libmx.h"

t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count) {
    t_straight_len *ret = (t_straight_len *)malloc(sizeof(t_straight_len *) * (line_count));
    int count1 = 0;
    char **arr_temp = NULL;
    char **arr_temp_sub = NULL;
    for (; count1 < line_count; count1++) {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        arr_temp_sub = mx_strsplit(arr_temp[1], ',');
        (ret + count1)->start = mx_strndup(arr_temp[0], mx_strlen(arr_temp[0]));
        (ret + count1)->dest = mx_strndup(arr_temp_sub[0], mx_strlen(arr_temp_sub[0]));
        (ret + count1)->len = mx_atoi(arr_temp_sub[1]);
        free((void *)arr_temp);
        free((void *)arr_temp_sub);
    }
    return ret;
}
