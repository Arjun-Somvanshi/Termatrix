#ifndef matrix_engine
#define matrix_engine
#define  SPEED  50
#define SPACED true
#define MODE 2 
int random_number_in_range(int lower, int upper);
void n_unique_in_array(int lower, int upper, int *arr, int unique);
void n_random_in_array(int lower, int upper, int *arr, int size);
void update_matrix(int matrix[1000][1000], int rows, int cols);
void update_matrix_2(int matrix[1000][1000], int rows, int cols, int *space_length, int *code_length, int *space_count, int *code_count, bool firstIteration);
void render_new_row(int matrix[1000][1000], int rows, int cols, int *space_length, int *code_length, int *space_count, int *code_count, bool firstIteration);
void render(int matrix[1000][1000], int rows, int cols);
void render_2(int matrix[1000][1000], int rows, int cols);
#endif //matrix_engine
