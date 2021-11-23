#define MAX_FILE_SIZE 1024
typedef struct s_index_island
{
    int index;
    char island[100];
} t_index_island;
int mx_read_island_count(char *data);

int mx_atoi(const char *str);

int **mx_create_matrix(char **text, int side_size);

char **mx_get_island_names(char **lines, int side_size);

int mx_check_dupl(char **main, char *sub);

t_index_island* mx_gen_index_struct(char ** trimed);
