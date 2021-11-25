#define MAX_FILE_SIZE 1024
typedef struct s_index_island
{
    int index;
    char *island;
} t_index_island;

typedef struct s_straight_len
{
    char *start;
    char *dest;
    int len;
} t_straight_len;

int mx_read_island_count(char *data);

int mx_atoi(const char *str);

int **mx_create_matrix(t_index_island *struct_arr, char **trimed, int side_size);

char **mx_get_island_names(char **lines, int side_size);

int mx_check_dupl(char **main, char *sub);

t_index_island *mx_gen_index_struct(char **trimed, int side_size);

t_straight_len mx_get_straight_len_struct(char **untrimed);

int mx_get_lines_count(char **text);
