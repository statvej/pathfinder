#define MAX_FILE_SIZE 1024

int mx_read_island_count(char*data);

int mx_atoi(const char * str);

int **mx_create_matrix(char** text, int side_size);

char **mx_get_island_names(char **lines, int side_size);

int mx_check_dupl(char **main, char *sub);
