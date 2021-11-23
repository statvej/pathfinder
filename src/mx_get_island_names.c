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

char **mx_get_island_names(char **untrimed, int side_size)
{
    int count_break = 0;
    char **lines = untrimed;

    char **trim = malloc(side_size * sizeof(char *));
    char **ret = trim;

    int count1 = 0;
    for (; count1 != side_size; count1++)
    {

        char *temp = (char *)malloc(sizeof(char) * 100 + 1);
        int count2 = 0;
        for (; lines[count1][count2] != '-'; count2++)
        {
            temp[count2] = lines[count1][count2];
        }
        if (mx_check_dupl(ret, temp) == 1)
        {

            *trim = (char *)malloc(mx_strlen(temp) * sizeof(char));
            *trim = mx_strndup(temp, mx_strlen(temp));

            trim++;

            count_break++;
        }
        if (count_break >= side_size)
        {
            break;
        }
        free(temp);
    }
    
    count1 = 0;
    char **arr_temp = NULL;

    for (; count1 != side_size; count1++)
    {
        char *temp = (char *)malloc(sizeof(char) * 100 + 1);
        arr_temp = mx_strsplit(untrimed[count1], '-');
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
        free((void*)arr_temp);
    }

    return ret;
} 
