#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
t_index_island *mx_gen_index_struct(char **trimed, int side_size)
{
    t_index_island *ret = (t_index_island*)malloc(sizeof(t_index_island)*side_size);
    
    for (int count = 0; count < side_size; count++)
    {
        ret[count].index = count;
        ret[count].island = (char*)malloc(sizeof(char)*mx_strlen(trimed[count]));
        ret[count].island = trimed[count];
    }
    return ret;
}
