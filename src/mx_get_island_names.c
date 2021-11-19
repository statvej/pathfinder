#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"
#include <stdio.h>
int mx_check_dupl(char **check, char *sub)
{

    
    printf("sub = %s\nmain[1] = %s\n", sub, check[1]);

    for (int i = 0; check[i] != NULL; i++)
    {
        
        if (mx_strcmp(check[i], sub) == 0)
        {
            printf("opa; i = %d!\n", i);
            return 0;
        }

    }

    return 1;
}

char **mx_get_island_names(char **untrimed, int side_size)
{
    int count_break = 0;
    char **lines = untrimed;
    mx_printstr("test\n");
    char **trim = (char **)malloc((side_size + 1) * (sizeof(char) * 100 + 1));
    for (int count = 0; count < side_size; count++)
    {
        trim[count] = (char *)malloc(sizeof(char) * 100 + 1);
        trim[count + 1] = NULL;
    }
    char **ret = trim;
    mx_printstr("test\n");
    int count1 = 0;

    for (; count1 != 101 * side_size; count1++)
    {
        char *temp = (char *)malloc(sizeof(char) * 100 + 1);
        int count2 = 0;
        for (; lines[count1][count2] != '-'; count2++)
        {
            temp[count2] = lines[count1][count2];
        }
        //printf("%d\n", mx_check_dupl((char **)trim, temp));
        if (mx_check_dupl(ret, temp) == 1)
        {
            printf("%s\n\n", temp);

            *trim = mx_strndup(temp, mx_strlen(temp));

            trim++;

            count_break++;
        }
        if (count_break >= side_size)
        {
            break;
        }
        free(temp);
        mx_printstr("test\n");
    }
    mx_printstr("test\n");
    *trim = "jycf";
    trim++;
    *trim = "ouefgv";
    trim++;
    *trim = "ouefgv";
//     for(count1 = 0; count1 != 101 * side_size; count1++){
// char

//     }

    return ret;
} //mx_check_dupl((char **)trim, temp, side_size) == true
