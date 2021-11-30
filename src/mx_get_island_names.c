#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int mx_check_dupl(char **check, char *sub)
{
    for (int i = 0; check[i] != NULL; i++)
    {

        if (mx_strcmp(check[i], sub) == 0)
        {

            return 0;
        }
    }
    return 1;
}

char **mx_get_island_names(char **untrimed, int side_size, int line_count)
{
    char **trim = malloc(side_size * sizeof(char *));
    char **ret = trim;

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

        if (mx_check_dupl(ret, temp) == 1)
        {

            *trim = (char *)malloc(mx_strlen(temp) * sizeof(char));
            *trim = mx_strndup(temp, mx_strlen(temp));

            trim++;
        }
        free((void *)temp);
        free((void *)arr_temp);
    }
    for (count1 = 0; count1 != line_count; count1++)
    {
        arr_temp = mx_strsplit(untrimed[count1], '-');
        char *temp = (char *)malloc(sizeof(char) * mx_strlen(arr_temp[1]));

        for (int count2 = 0; arr_temp[1][count2] != ','; count2++)
        {
            temp[count2] = arr_temp[1][count2];
        }

        if (mx_check_dupl(ret, temp) == 1)
        {

            *trim = (char *)malloc(mx_strlen(temp) * sizeof(char));
            *trim = mx_strndup(temp, mx_strlen(temp));

            trim++;
        }
        free((void *)temp);
        free((void *)arr_temp);
    }

    *trim = NULL;

    return ret;
}
