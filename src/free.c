#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

void mx_free_matrix(int **ptr, int len) {
    if (len < 0)
        while (*ptr) {
            free(*ptr);
            *ptr++ = NULL;
        }
    else
        while (len) {
            free(ptr[len]);
            ptr[len--] = NULL;
        }

    free(ptr);
}
void mx_free_route(t_route *route) {
    free((void *)route->list);
    free((void *)route);
}
