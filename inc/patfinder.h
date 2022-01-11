#define MAX_FILE_SIZE 1024
#define INT_MAX 2147483647
#define DELIM_COUNT 40
#define ARROW " -> "
#define PLUS_SIGN " + "
#define EQUAL_SIGN " = "

typedef struct s_ind_len {
    int start;
    int dest;
    int len;
} t_ind_len;
typedef struct s_route // for saving and printing results
{
    int start;
    int dest;
    int *list;
} t_route;

typedef struct s_index_island {
    int index;
    char *island;

} t_index_island;

typedef struct s_straight_len {
    char *start;
    char *dest;
    long int len;

} t_straight_len;

// Processing

t_route * mx_algorithm(t_route *struct_route, int **matrix, int side_size, t_ind_len *ind_len, int namesLen, int *route_count);
t_route *temp_path_completion(t_route *route, int path_num);
t_route *
post_algorithm_processing(t_route *struct_route, int side_size, t_ind_len *ind_len, int namesLen, int path_num);
int *conect_routes(int *main, int *sub, int start, int dest, int side_size);
t_route *mx_insert_route(int *route_count, t_route *route, int stage, int start, int dest, int side_size);
t_route *mx_multi_path_detector(int **matrix, t_route *route, int side_size, int *route_count);

// Checks

void mx_print_matrix(int **matrix, int side_size);
void print_route_struct(t_route *arr_route, int elements);
void print_index_struct(t_index_island *struct_index, int elem_num);
void print_len_struct(t_straight_len *arr_len, int namesLen);
void print_ind_len_struct(t_ind_len *arr_len, int namesLen);
void print_single_route_struct(t_route route);
void conect_routes_print_check(int *main, int *sub, int start, int dest, int side_size);

// Utilities

int mx_read_island_count(char *data);
int mx_check_dupl(char **main, char *sub);
int mx_get_lines_count(char **text);
int get_index_route(int *list);
int mx_atoi(const char *str);
int is_path_straight(int start, int dest, int namesLen, t_ind_len *ind_len);
int get_index_from_route_struct(int start, int dest, int path_num, t_route *route);
int get_num_index_in_arr(int num, int *arr, int arr_size);
int *reverse_route(int *list, int value_size);
int get_dist_betw_isl(int start, int dest, t_ind_len *ind_len, int namesLen);
int **mx_copy_matrix(int **orig, int side_size);
int *mx_copy_route_list(int *list, int side_size);

// Creating data structures

t_route *mx_init_route_struct(int side_size);
t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count);
t_index_island *mx_gen_index_struct(char **trimed, int side_size);
char **mx_get_island_names(char **lines, int side_size, int line_count);
t_ind_len *make_ind_len_struct(t_index_island *struct_arr, t_straight_len *arr_len, int namesLen, int side_size);
int **mx_create_matrix(t_index_island *struct_arr, t_straight_len *struct_len, int side_size, int names_len);

// Free functions

void mx_free_matrix(void **ptr, int len);
void mx_free_route(t_route *route, int path_num);
void mx_free_strght_len_struct(t_straight_len *straight_len, int namesLen);
void mx_free_ind_len(t_ind_len *ind_len);
void mx_free_ind_isl(t_index_island *ind_isl, int side_size);

// Result printing

void mx_print_result(
    t_route *route, t_index_island *ind_isl, t_ind_len *ind_len, int path_num, int **matrix, int namesLen);
void mx_print_delim(void);

// Errors

void print_int_err(int n);
void print_line_invalid(int linenum);
void mx_check_args(int argc);
void mx_check_file(int fd, const char *filename);
void mx_check_size(const char *filename);
void mx_check_length(const char *length);
void mx_check_sum_length(t_straight_len *str_len, int namesLen, char **lines);
