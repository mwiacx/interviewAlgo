/*
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct pos_t{
    int found;
    int row; // = real row-1
    int column; // = real column-1
} retPos;

retPos Find(int *matrix, int rows, int columns, int number)
{
    retPos ret = {0,0,0};

    if (rows <= 0 || columns <= 0)
    {
        printf("Eorror(Wrong Param): rows = %d, columns = %d\n", rows, columns);
        return ret;
    }

    int i = 0, j = columns-1;
    while (i < rows && j >= 0 && matrix != NULL){

        if (matrix[i * columns + j] == number)
        {
            ret.column = j;
            ret.row = i;
            ret.found = 1;
            return ret;
        }
        else if (matrix[i * columns + j] > number)

            j--;
        else
            i++;
    }

    return ret;
}

int main(void){

    //define Matrix
    int matrix[4*4] = {1,2,8,9,
                        2,4,9,12,
                        4,7,10,13,
                        6,8,11,15};
    
    retPos ret = Find(matrix, 4, 4, 7);

    if(ret.found)
        printf("Result: Found in row %d, column %d\n", ret.row+1, ret.column+1);
    else
        printf("Result: Not Found\n");

    return 0;
}