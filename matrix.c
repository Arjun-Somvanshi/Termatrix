#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "libutil.h"
#include "matrix_engine.h"

int main(){
    initscr();
    srandom(time(0));
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    int rows = 36, cols = 150;
    curs_set(0);
    getmaxyx(stdscr, rows, cols);
    int matrix[1000][1000], space_length[1000], code_length[1000], space_count[1000], code_count[1000];
    bool firstIteration = true;
    n_random_in_array(4, rows, space_length, cols);
    n_random_in_array(6, rows, code_length, cols);
    fill_zero(space_count, cols);
    fill_zero(code_count, cols);
    fill_space_2D(matrix, rows, cols);
    //render loop
    while(true)
    {
        if(MODE == 1)
        {
            //********************* 
            //update the matrix
            //*********************
            if(firstIteration){
                //first iteration
                render_new_row(matrix, rows, cols, space_length, code_length, space_count, code_count, firstIteration);
                firstIteration = false;
            }
            else{
                //update the whole matrix
                update_matrix(matrix, rows, cols);
                //render the first row
                render_new_row(matrix, rows, cols, space_length, code_length, space_count, code_count, firstIteration);

            }
            // render
            render(matrix, rows, cols);
            refresh();
            napms(SPEED);
        }
        else if(MODE == 2)
        {
            if(firstIteration)
            {
                //first iteration
                update_matrix_2(matrix, rows, cols, space_length, code_length, space_count, code_count, firstIteration);
                firstIteration = false;
            }
            else
            {
                update_matrix_2(matrix, rows, cols, space_length, code_length, space_count, code_count, firstIteration);
            }
            // render
            render(matrix, rows, cols);
            refresh();
            napms(SPEED);
        }
    }
    return 0; 
}

