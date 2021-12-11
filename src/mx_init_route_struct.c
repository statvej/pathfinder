#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

t_route *mx_init_route_struct(int side_size) {
    t_route *ret = (t_route *)malloc((side_size * (side_size - 1)) / 2 * sizeof(t_route *));
    int grand_count = 0;
    for (int count1 = 0; count1 < side_size; count1++) {
        for (int count2 = 1; count2 + count1 < side_size; count2++) {
            ret[grand_count].start = count1;
            ret[grand_count].dest = count2 + count1;
            ret[grand_count].list = (int *)malloc(sizeof(int) * side_size);
            for (int i = 0; i < side_size; i++)
            {
                ret[grand_count].list[i] = -1;
            }
            
            
            ret[grand_count].links_count = 0;
            grand_count++;
        }
        if (grand_count >= (side_size * (side_size - 1)) / 2) {
            return ret;
        }
    }

    return ret;
}
