/******************************************************************************

This program reads a file named "a23.dat" with an array and calculates either
the average of a row of integers or a column of integers and prints it out.

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

int get_info(int* rows, int* cols, int array[][MAX_COLS]);

void print_all(int rows, int cols, int array[][MAX_COLS]);

void row_avg(int row_of_interest, int cols, int array[][MAX_COLS]);

void col_avg(int col_of_interest, int rows, int array[][MAX_COLS]);

/************************************************************************/

int main() {

  int rows;
  int cols;
  int num;
  int array[MAX_ROWS][MAX_COLS];
  int row_or_col;

  if(get_info(&rows, &cols, array) == 0) {
    print_all(rows, cols, array);
    printf("\nEnter 1 to average a row, 2 to average a column: ");
    scanf("%d", &row_or_col);
    if(row_or_col == 1) {
      printf("\nEnter the row to be averaged (from 0 to %d): ", rows - 1);
      scanf("%d", &num);
      row_avg(num, cols, array);
    } else {
      printf("\nEnter the col to be averaged (from 0 to %d): ", cols - 1);
      scanf("%d", &num);
      col_avg(num, rows, array);
    }
  } else
    printf("\nThe file failed to open for reading.\n\n");
  
  return 0;
}

/************************************************************************/

// This function reads the integer array from a23.dat file
int get_info(int* rows, int* cols, int array[][MAX_COLS]) {

  int r;
  int c;
  FILE* sp_input;
  if((sp_input = fopen("a23.dat", "r")) != NULL) {
    fscanf(sp_input, "%d %d", rows, cols);

    for(r = 0; r < *rows; r++)
      for(c = 0; c < *cols; c++)
        fscanf(sp_input, "%d", &array[r][c]);
    
    fclose(sp_input);

    return 0;
  } else
    return 1;
}

/************************************************************************/

// This function prints all the elements of the 2D array
void print_all(int rows, int cols, int array[][MAX_COLS]) {

  int r;
  int c;

  for(r = 0; r < rows; r++) {
    printf("\n");
    for(c = 0; c < cols; c++)
      printf("%4d", array[r][c]);
  }
  printf("\n");

  return;
}

/************************************************************************/

// This function calculates the average of a particular row
void row_avg(int row_of_interest, int cols, int array[][MAX_COLS]) {

  int c;
  int sum = 0;

  printf("\n");
  for(c = 0; c < cols; c++) {
    printf("%4d", array[row_of_interest][c]);
    sum += array[row_of_interest][c];
  }

  printf(" avg = %0.1f\n\n", (float) sum/cols);

  return;
}

/************************************************************************/

// This function calculates the average of a particular column
void col_avg(int col_of_interest, int rows, int array[][MAX_COLS]) {

  int r;
  int sum = 0;

  printf("\n");
  for(r = 0; r < rows; r++) {
    printf("%4d\n", array[r][col_of_interest]);
    sum += array[r][col_of_interest];
  }

  printf(" avg = %0.1f\n\n", (float) sum/rows);

  return;
}