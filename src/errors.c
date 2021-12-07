#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>

//prints message to stderr stream
static void printerr(const char *str) {
    write(2, str, mx_strlen(str));
}

static void print_line_invalid(int linenum) {
    printerr("error: line ");
    printerr(mx_itoa(linenum));
    printerr(" is not valid\n");
    exit(0);
}

//check number of command-line arguments
void mx_check_args(int argc) {
    if (argc != 2) {
        printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
}

//check if file exists
void mx_check_file(int fd, const char *filename) {
    if (fd == -1) {
        printerr("error: file ");
        printerr(filename);
        printerr(" does not exist\n");
        exit(0);
    }
}

//check if file is empty
void mx_check_size(const char *filename) {
    printerr("error: file ");
    printerr(filename);
    printerr(" is empty\n");
    exit(0);
}

//check if number of islands or bridge length is valid
void mx_check_length(const char *length, int linenum) {
    for (int i = 0; length[i] != '\0'; i++)
        if(!mx_isdigit(length[i]))
            print_line_invalid(linenum);
    if(mx_atoi(length) <= 0)
        print_line_invalid(linenum);
}

//check any line
void mx_check_line( const char *island1, const char *island2,
                    const char *length, int linenum) {
    //check if not empty fields
    if(!island1 || !island2 || !length)
        print_line_invalid(linenum);
    //check for valid fields format
    for (int i = 0; island1[i] != '\0'; i++)
        if(!mx_isalpha(island1[i]))
            print_line_invalid(linenum);
    for (int i = 0; island2[i] != '\0'; i++)
        if(!mx_isalpha(island2[i]))
            print_line_invalid(linenum);
    //duplicate names
    if (!mx_strcmp(island1, island2))
        print_line_invalid(linenum);
    //non-negative length
    mx_check_length(length, linenum);
}

//check number of islands
//last = 0 -> intermediate call, last = 1 -> last call
void mx_check_islands_num(int size_so_far, int size_max, int last) {
    if(!last) {
        if (size_so_far >= size_max) {
            printerr("error: invalid number of islands\n");
            exit(0);
        }
    } else {
        if(size_so_far != size_max) {
            printerr("error: invalid number of islands\n");
            exit(0);
        }
    }
}

//check for duplicate bridges
void mx_check_duplicates(int weight_so_far) {
    if (weight_so_far < INT_MAX) {
        printerr("error: duplicate bridges\n");
        exit(0);
    }
}

//check sum of all bridges
void mx_check_sum(int *sum_so_far, int next) {
    if (INT_MAX - *sum_so_far < next) {
        printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    *sum_so_far += next;
}
