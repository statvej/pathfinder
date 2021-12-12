#define MAX_FILE_SIZE 1024
#define INT_MAX 2147483647
#define MAX_STOPS 5000
// typedef struct s_ind_list {
//     int index;
//     struct s_ind_list *next;

// } t_ind_list;

typedef struct s_route //for saving and printing results
{
    int start;
    int dest;
    int links_count;
    int *list;
} t_route;

typedef struct s_index_island {
    int index;
    char *island;

} t_index_island;

typedef struct s_straight_len {
    char *start;
    char *dest;
    int len;

} t_straight_len;
 

//Processing


t_route* mx_algorithm(t_route *struct_route, int **matrix, int side_size);



//Checks

void mx_print_matrix(int **matrix, int side_size);
void print_route_struct(t_route *arr_route, int elements);
void print_index_struct(t_index_island *struct_index, int elem_num);
void print_len_struct(t_straight_len * arr_len, int namesLen);


//Utilities

int mx_read_island_count(char *data);
int mx_check_dupl(char **main, char *sub);
int mx_get_lines_count(char **text);
int get_index_route(int *list);
int mx_atoi(const char *str);

//Creating data structures

t_route* mx_init_route_struct(int side_size);
t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count);
t_index_island *mx_gen_index_struct(char **trimed, int side_size);
char **mx_get_island_names(char **lines, int side_size, int line_count);

//Free functions

int **mx_create_matrix(t_index_island *struct_arr, t_straight_len *struct_len, int side_size, int names_len);
void mx_free_matrix(int **ptr, int len);
void mx_free_route(t_route *route);


//Errors
void mx_check_args(int argc);
void mx_check_file(int fd, const char *filename);
void mx_check_size(const char *filename);
void mx_check_length(const char *length, int linenum);
void mx_check_line(const char *island1, const char *island2,
                   const char *length, int linenum);
void mx_check_islands_num(int size_so_far, int size_max, int last);
void mx_check_duplicates(int weight_so_far);
void mx_check_sum(int *sum_so_far, int next);
