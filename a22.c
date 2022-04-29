/******************************************************************************

This program reads a file named "a22.dat" with scores and fills the
blank column with the scores taken from the user as an input
and edits the file accordingly.

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#define MAX_ROWS 20
#define MAX_COLS 30

int get_info(int* rows, int* cols, int scores[][MAX_COLS]);

void print_all(int rows, int cols, int scores[][MAX_COLS]);

int add_score(int rows, int cols, int scores[][MAX_COLS]);

void update_file(int rows, int cols, int scores[][MAX_COLS]);

/************************************************************************/

int main() {

  int rows;
  int cols;
  int scores[MAX_ROWS][MAX_COLS];

  if(get_info(&rows, &cols, scores) == 0) {
    print_all(rows, cols, scores);
    cols = add_score(rows, cols, scores);
    print_all(rows, cols, scores);
    update_file(rows, cols, scores);
  } else 
    printf("\nThe file failed to open for reading.");
  
  return 0;
}

/************************************************************************/

// Reads the scores from the a22.bat file
int get_info(int* rows, int* cols, int scores[][MAX_COLS]) {

  int r;
  int c;
  FILE* sp_input;
  if((sp_input = fopen("a22.dat", "r")) != NULL) {
    fscanf(sp_input, "%d %d", rows, cols);

    for(r = 0; r < *rows; r++)
      for(c = 0; c < *cols; c++)
        fscanf(sp_input, "%d", &scores[r][c]);
    
    fclose(sp_input);

    return 0;
  } else
    return 1;
}

/************************************************************************/

// Prints all the scores
void print_all(int rows, int cols, int scores[][MAX_COLS]) {
  int r;
  int c;
  printf("    ");
  for(c = 0; c < cols; c++)
    printf("%4d", c);
  printf("\n");

  for(r = 0; r < rows; r++) {
    printf("%4d", r);

    for(c = 0; c < cols; c++)
      printf("%4d", scores[r][c]);
    printf("\n");
  }
  printf("\n");

  return;
}

/************************************************************************/

// Takes the scores as inputs from the user
int add_score(int rows, int cols, int scores[][MAX_COLS]) {
  int r;

  printf("\nEnter the %d scores for test %d: ", rows, cols);

  for(r = 0; r < rows; r++)
    scanf("%d", &scores [r][cols]);

  return cols + 1;
}

/************************************************************************/

// Adds the scores into the file
void update_file(int rows, int cols, int scores[][MAX_COLS]) {

  int r;
  int c;
  FILE* sp_output;

  if((sp_output = fopen("a22.dat", "w")) != NULL) {
    fprintf(sp_output, "%d %d\n", rows, cols);

    for(r = 0; r < rows; r++) {
      for(c = 0; c < cols; c++)
        fprintf(sp_output, "%4d", scores[r][c]);
      fprintf(sp_output, "\n");
    }
    fclose(sp_output);
  } else
    printf("\nUnable to open a22.dat\n\n");
  
  return;
}