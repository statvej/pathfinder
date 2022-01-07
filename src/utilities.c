#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"

int mx_read_island_count(char *data) {

    int res = 0;
    int del = mx_get_char_index((const char *)data, '\n');
    char *temp = mx_strnew(10);
    for (int count = 0; count <= del; count++) {
        temp[count] = data[count];
    }

    res = mx_atoi((const char *)temp);
    free((void *)temp);
    return res;
}

int mx_get_lines_count(char **text) {
    if (!text) {
        return 0;
    }
    int count = 0;
    for (; text[count] != NULL; count++) {
    }
    return count;
}

int mx_atoi(const char *str) {
    if (!str)
        return 0;

    char *temp = (char *)str;
    int res = 0;
    int count = mx_strlen(temp);
    for (int i = 0; i <= count && mx_isdigit(str[i]); i++) {
        res = res * 10 + (str[i] - 48);
    }

    return res;
}

int mx_check_dupl(char **check, char *sub) {
    int count = 0;
    for (; check[count] != NULL; count++) {

        if (mx_strcmp(check[count], sub) == 0) {

            return 0;
        }
    }
    return 1;
}

int get_index_route(int *list) {
    int res = 0;
    while (list[res] != -1) {
        res++;
    }

    return res;
}

int *reverse_route(int *list, int value_size) {
    int *temp = (int *)malloc(sizeof(int) * value_size);
    for (int i = 0; i < value_size; i++) {
        temp[i] = list[value_size - 1 - i];
    }
    for (int i = 0; i < value_size; i++) {
        list[i] = temp[i];
    }
    free(temp);
    return list;
}

int **mx_copy_matrix(int **orig, int side_size) {
    int **ret = (int **)malloc(side_size * sizeof(int *));
    for (int i = 0; i < side_size; i++) {
        ret[i] = (int*) malloc(side_size * sizeof(int));
    }
    for (int count1 = 0; count1 < side_size; count1++)
    {
        for (int count2 = 0; count2 < side_size; count2++)
        {
            ret[count1][count2] = orig[count1][count2];
        }
    }
    return ret;
}
int *mx_copy_route_list(int*list, int side_size){
    int* ret = (int*)malloc(sizeof(int) * side_size);
    for (int i = 0; i < side_size; i++)
    {
        ret[i] = list[i];
    }
    return ret;
}
