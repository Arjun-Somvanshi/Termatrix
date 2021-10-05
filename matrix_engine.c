#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "libutil.h"
#include "matrix_engine.h"


int random_number_in_range(int lower, int upper){
    return (random() % (upper - lower + 1)) + lower;
}

void n_unique_in_array(int lower, int upper, int *arr, int unique)
{
    int random_number = 0, i=0, index_of_random; 
    //print_arr(arr, 10);
    while(i!=unique) 
    {
       //printf("Size of array: %d\n", i);
       //print_arr(arr, i);
       random_number = random_number_in_range(lower, upper);
       //printf("The new random number is: %d\n", random_number);
       index_of_random = _in(random_number, arr, i);
       //printf("The index of random number is: %d\n", index_of_random);
       if(index_of_random==-1)
       {
           arr[i] = random_number;
           i++;
           sort(arr, i);
       }
    }
}

void n_random_in_array(int lower, int upper, int *arr, int size)
{
    int random_number = 0, i=0, index_of_random; 
    //print_arr(arr, 10);
    while(i!=size) 
    {
       random_number = random_number_in_range(lower, upper);
       index_of_random = _in(random_number, arr, i);
       arr[i] = random_number;
       i++;
    }
}

void update_matrix(int matrix[1000][1000], int rows, int cols){
    for (int i = rows; i>0; i--) 
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i-1][j] != ' ')
                if(matrix[i-2][j] == ' ' || matrix[i][j] == ' ')
                    matrix[i-1][j] = random_number_in_range(33,126);

            matrix[i][j] = matrix[i-1][j];
    
        }
    }
}

void render_new_row(int matrix[1000][1000], int rows, int cols, int *space_length, int *code_length, int *space_count, int *code_count, bool firstIteration)
{
// renders the top most row of the matrix
    if(firstIteration) 
    {
        for(int i=0; i<cols; i++)
        {
            if(i%2==1 && SPACED)
            {
                matrix[0][i]=' ';
            }
            else
            {
                int chance = random_number_in_range(0,5);
                switch(chance)
                {
                    case 0:
                        matrix[0][i] = random_number_in_range(33,126);
                        code_count++;
                        break;
                    default:
                        matrix[0][i] = ' ';
                        space_count++;
                }

            }
        }
    }

    else
    {
        for (int i = 0; i < cols; ++i) 
        {
            if(i%2==1 && SPACED){
                matrix[0][i] = ' ';
            }
            else
            {
                if(matrix[1][i] == ' ')
                {
                    if(space_count[i]<space_length[i])
                    {
                        matrix[0][i] = ' ';
                        space_count[i]++;
                    }
                    else
                    {
                        matrix[0][i] = random_number_in_range(33,126);
                        code_count[i]++;
                        space_count[i] = 0;
                        space_length[i] = random_number_in_range(4,rows);
                        
                    }

                }
                else
                {
                    if(code_count[i]<code_length[i])
                    {
                        matrix[0][i] = random_number_in_range(33,126);
                        code_count[i]++;
                    }
                    else
                    {
                        matrix[0][i] = ' ';
                        space_count[i]++;
                        code_count[i] = 0;
                        code_length[i] = random_number_in_range(6,rows);
                        
                    }
                }

            }
        }
    }
}

void update_matrix_2(int matrix[1000][1000], int rows, int cols, int *space_length, int *code_length, int *space_count, int *code_count, bool firstIteration)
{
// renders the top most row of the matrix
    if(firstIteration){
        for(int i=0; i<cols; i++)
        {
            if(SPACED && i%2==1)
            {
                matrix[0][i] = ' ';
            }
            else{
                if(i%2==1 && SPACED)
                {
                    matrix[0][i]=' ';
                }
                else
                {
                    int chance = random_number_in_range(0,5);
                    switch(chance)
                    {
                        case 0:
                            matrix[0][i] = random_number_in_range(33,126);
                            code_count++;
                            break;
                        default:
                            matrix[0][i] = ' ';
                            space_count++;
                    }

                }
            }

        }
    }
    else{
        for(int i=0; i<cols; i++)
        {
            if(SPACED && i%2==1)
            {
                matrix[0][i] = ' ';
            }
            else{
                if(matrix[0][i]== ' ')
                {
                    if(space_count[i]<=space_length[i])
                    {
                       //column shift downward
                       for(int j=rows; j>0; j--)
                       {
                           if(matrix[j-1][i]!= ' ' && matrix[j][i] == ' ')
                               matrix[j][i] = random_number_in_range(33, 126);
                           else
                               matrix[j][i] = matrix[j-1][i];
                       }
                       space_count[i]++;
                    }
                    else{
                        space_count[i] = 0;
                        space_length[i] = random_number_in_range(4,rows);
                       //column shift downward
                       for(int j=rows; j>0; j--)
                       {
                           if(matrix[j-1][i]!= ' ' && matrix[j][i] == ' ')
                               matrix[j][i] = random_number_in_range(33, 126);
                           else
                               matrix[j][i] = matrix[j-1][i];
                       }
                        matrix[0][i] = random_number_in_range(33,126);
                        code_count[i]++;
                    }
                }
                else
                {
                    if(code_count[i]<=code_length[i])
                    {
                        //find the first space in the column and a random charater there
                       int shift_stopper;// where to stop shifting
                       for(int j=1; j<rows; j++)
                           if(matrix[j][i]==' ')
                           {
                               matrix[j][i] = random_number_in_range(33,126);
                               shift_stopper = j;
                               break;
                           }
                       code_count[i]++;
                       //column shift
                       for(int j=rows; j>shift_stopper; j--)
                       {
                           if(matrix[j-1][i]!= ' ' && matrix[j][i] == ' ')
                               matrix[j][i] = random_number_in_range(33, 126);
                           else
                               matrix[j][i] = matrix[j-1][i];
                       }

                    }
                    else
                    {
                       code_count[i] = 0;
                       code_length[i] = random_number_in_range(6, rows);
                       //col shift
                       for(int j=rows; j>0; j--)
                       {
                           if(matrix[j-1][i]!= ' ' && matrix[j][i] == ' ')
                               matrix[j][i] = random_number_in_range(33, 126);
                           else
                               matrix[j][i] = matrix[j-1][i];
                       }
                       matrix[0][i] = ' ';
                       space_count[i]++;

                    }
                }

            }
        }
    }
}

void render(int matrix[1000][1000], int rows, int cols){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            int pair = 1;
            if(matrix[i][j]!= ' ')
                if(matrix[i+1][j]== ' ')
                    pair = 2;
            attron(COLOR_PAIR(pair));
            mvprintw(i, j, "%c", matrix[i][j]);
        }
    }
}

void render_2(int matrix[1000][1000], int rows, int cols){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            mvprintw(i, j, "%c", matrix[i][j]);
        }
    }
}
