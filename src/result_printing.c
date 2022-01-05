#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"

void mx_print_delim(void) {
    for (int i = 0; i < DELIM_COUNT; i++) {
        mx_printchar('=');
    }
    mx_printchar('\n');
}

void mx_print_path(t_route route, t_index_island *ind_isl) {

    mx_printstr("Path: ");
    mx_printstr(ind_isl[route.start].island);
    mx_printstr(ARROW);
    mx_printstr(ind_isl[route.dest].island);
    mx_printchar('\n');
}

void mx_print_route(t_route route, t_index_island *ind_isl) {
    mx_printstr("Route: ");
    int islands_count = get_index_route(route.list);
    for (int count = 0; count < islands_count; count++) {
        mx_printstr(ind_isl[route.list[count]].island);
        if (route.list[count + 1] != -1) {
            mx_printstr(ARROW);
        }
    }
    mx_printchar('\n');
}

int get_dist_betw_isl(int start, int dest, t_ind_len *ind_len, int namesLen) {
    for (int i = 0; i < namesLen; i++) {
        if (start == ind_len[i].start && dest == ind_len[i].dest) {
            return ind_len[i].len;
        }
        if (dest == ind_len[i].start && start == ind_len[i].dest) {
            return ind_len[i].len;
        }
    }

    return 0;
}

void mx_print_distance(int *list, t_ind_len *ind_len, int result, int namesLen) {
    mx_printstr("Distance: ");
    if (list[2] != -1) {
        int islands_count = get_index_route(list);
        for (int count = 0; count < islands_count - 1; count++) {
            int temp_len = get_dist_betw_isl(list[count], list[count + 1], ind_len, namesLen);
            mx_printint(temp_len);
            if (list[count + 2] != -1)
                mx_printstr(PLUS_SIGN);
        }
        mx_printstr(EQUAL_SIGN);
    }
    mx_printint(result);
    mx_printchar('\n');
}

void mx_print_result(
    t_route *route, t_index_island *ind_isl, t_ind_len *ind_len, int side_size, int **matrix, int namesLen) {
    int path_num = side_size * (side_size - 1) / 2;
    for (int count = 0; count < path_num; count++) {
        int result = matrix[route[count].start][route[count].dest];
        mx_print_delim();

        mx_print_path(route[count], ind_isl);

        mx_print_route(route[count], ind_isl);

        mx_print_distance(route[count].list, ind_len, result, namesLen);

        mx_print_delim();
    }
}
