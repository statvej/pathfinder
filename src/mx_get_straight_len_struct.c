#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"

t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count)
{
    t_straight_len *ret = (t_straight_len *)malloc(sizeof(t_straight_len *) * line_count);
    int count1 = 0;
    char **arr_temp = NULL;
    for (; count1 != line_count; count1++)
    {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        char *temp = (char *)malloc(sizeof(char) * mx_strlen(arr_temp[1]));

        for (int count2 = 0; arr_temp[0][count2] != '\0'; count2++)
        {
            temp[count2] = arr_temp[0][count2];
        }

        ret[count1].start = (char *)malloc(mx_strlen(temp) * sizeof(char));
        ret[count1].start = mx_strndup(temp, mx_strlen(temp));

        free((void *)temp);

        temp = (char *)malloc(sizeof(char) * mx_strlen(arr_temp[1]));

        for (int count2 = 0; arr_temp[1][count2] != ','; count2++)
        {
            temp[count2] = arr_temp[1][count2];
        }
        ret[count1].dest = (char *)malloc(mx_strlen(temp) * sizeof(char));
        ret[count1].dest = mx_strndup(temp, mx_strlen(temp));

        free((void *)temp);
        free((void *)arr_temp);
        arr_temp = mx_strsplit(untrimed[count1], ',');
        temp = (char *)malloc(sizeof(char) * mx_strlen(arr_temp[1]));
        for (int count2 = 0; arr_temp[1][count2] != '\0'; count2++)
        {
            temp[count2] = arr_temp[1][count2];
        }
        ret[count1].len = mx_atoi(temp);
    }
    

    return ret;
}
