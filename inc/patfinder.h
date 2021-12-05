#define MAX_FILE_SIZE 1024
#define INT_MAX 2147483647

typedef struct s_ind_list {
    int index;
    struct s_ind_list *next;

} t_ind_list;

typedef struct s_route //for saving and printing results
{
    int start;
    int dest;
    t_ind_list *list;
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

int mx_read_island_count(char *data);

int mx_atoi(const char *str);

int **mx_create_matrix(t_index_island *struct_arr, t_straight_len *struct_len, int side_size, int names_len);

char **mx_get_island_names(char **lines, int side_size, int line_count);

int mx_check_dupl(char **main, char *sub);

t_index_island *mx_gen_index_struct(char **trimed, int side_size);

t_straight_len *mx_get_straight_len_struct(char **untrimed, int line_count);

int mx_get_lines_count(char **text);

void mx_print_matrix(int **matrix, int side_size);

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
