#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"

void mx_printchar_err(char c) {
    write(2, (char *)&c, 1);
}

void print_int_err(int n) {
    if (n == 0) {
        mx_printchar_err('0');
        return;
    }
    else if (n > 0) {
        int comper = 1000000000;
        int fnumber;
        while (n / comper < 1) {
            comper = comper / 10;
        }
        while (comper >= 1) {
            fnumber = n / comper + 48;
            mx_printchar_err(fnumber);
            n = n - (n / comper * comper);
            comper = comper / 10;
        }
    }
    else if (n < 0 && n > -2147483648) {
        n = n * -1;
        int comper = 1000000000;
        int fnumber;
        while (n / comper < 1) {
            comper = comper / 10;
        }
        mx_printchar_err('-');
        while (comper >= 1) {
            fnumber = n / comper + 48;
            mx_printchar_err(fnumber);
            n = n - (n / comper * comper);
            comper = comper / 10;
        }
    }
    else if (n == -2147483648) {
        n = 147483648;
        int comper = 1000000000;
        int fnumber;
        while (n / comper < 1) {
            comper = comper / 10;
        }
        mx_printchar_err('-');
        mx_printchar_err('2');
        while (comper >= 1) {
            fnumber = n / comper + 48;
            mx_printchar_err(fnumber);
            n = n - (n / comper * comper);
            comper = comper / 10;
        }
    }
}

// prints message to stderr stream
static void printerr(const char *str) {
    write(2, str, mx_strlen(str));
}

void print_line_invalid(int linenum) {
    printerr("error: line ");
    print_int_err(linenum);
    printerr(" is not valid\n");
    exit(0);
}

// check number of command-line arguments
void mx_check_args(int argc) {
    if (argc != 2) {
        printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
}

// check if file exists
void mx_check_file(int fd, const char *filename) {
    if (fd == -1) {
        printerr("error: file ");
        printerr(filename);
        printerr(" does not exist\n");
        exit(0);
    }
}

// check if file is empty
void mx_check_size(const char *filename) {
    printerr("error: file ");
    printerr(filename);
    printerr(" is empty\n");
    exit(0);
}

// check if number of islands or bridge length is valid
void mx_check_length(const char *data) {
    for (int i = 0; data[i] != '\n'; i++)
        if (!mx_isdigit(data[i])) {
            free((void *)data);
            print_line_invalid(1);
        }
    if (mx_atoi(data) <= 1) {
        free((void *)data);
        print_line_invalid(1);
    }
}

void mx_check_sum_length(t_straight_len *str_len, int namesLen, char **lines) {
    long int sum = 0;
    for (int i = 0; i < namesLen; i++) {
        sum += str_len[i].len;
    }
    if (sum >= INT_MAX) {
        mx_free_matrix((void*)lines, namesLen + 1);
        mx_free_strght_len_struct(str_len, namesLen);
        printerr("error: sum of bridges lengths is too big");
        exit(0);
    }
}

// // check any line
// void mx_check_line(const char *island1, const char *island2, const char *length, int linenum) {
//     // check if not empty fields
//     if (!island1 || !island2 || !length)
//         print_line_invalid(linenum);
//     // check for valid fields format
//     for (int i = 0; island1[i] != '\0'; i++)
//         if (!mx_isalpha(island1[i]))
//             print_line_invalid(linenum);
//     for (int i = 0; island2[i] != '\0'; i++)
//         if (!mx_isalpha(island2[i]))
//             print_line_invalid(linenum);
//     // duplicate names
//     if (!mx_strcmp(island1, island2))
//         print_line_invalid(linenum);
//     // non-negative length
//     mx_check_length(length, linenum);
// }

// // check number of islands
// // last = 0 -> intermediate call, last = 1 -> last call
// void mx_check_islands_num(int size_so_far, int size_max, int last) {
//     if (!last) {
//         if (size_so_far >= size_max) {
//             printerr("error: invalid number of islands\n");
//             exit(0);
//         }
//     }
//     else {
//         if (size_so_far != size_max) {
//             printerr("error: invalid number of islands\n");
//             exit(0);
//         }
//     }
// }

// // check for duplicate bridges
// void mx_check_duplicates(int weight_so_far) {
//     if (weight_so_far < INT_MAX) {
//         printerr("error: duplicate bridges\n");
//         exit(0);
//     }
// }

// // check sum of all bridges
// void mx_check_sum(int *sum_so_far, int next) {
//     if (INT_MAX - *sum_so_far < next) {
//         printerr("error: sum of bridges lengths is too big\n");
//         exit(0);
//     }
//     *sum_so_far += next;
// }
