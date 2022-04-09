/******************************************************************************

This program reads a file named "a16.dat" and calculates the average of
all the integer numbers written in the file

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#include <limits.h>

int get_avg_max_min(float *average, int *max, int *min);
void output(float average, int max, int min);

/************************************************************************/

int main(void) {
  float average;
  int max;
  int min;
  int read_error;

  read_error = get_avg_max_min(&average, &max, &min);
  if(!read_error)
    output(average, max, min);

  return 0;
}

/************************************************************************/

/* This function reads and calculates the average, maximum, and minimum
value in a18.dat file */
int get_avg_max_min(float *average, int *max, int *min) {
  FILE* sp_input;
  *max = INT_MIN;
  *min = INT_MAX;
  int count;

  sp_input = fopen("a18.dat", "r");

  if (sp_input == NULL) {
    printf("Unable to open the file a18.dat\n");
    return 1;
  } else {
    int num;
    count = 0;
    while(fscanf(sp_input, "%d\n", &num) != EOF) {
      if(*min > num)
        *min = num;
      if(*max < num)
        *max = num;
      *average += num;
      count += 1;
    }
    *average /= count;
    fclose(sp_input);
  }

  return 0;
}

/************************************************************************/

// This function prints out the output
void output(float average, int max, int min) {
  printf("The average is %0.3f\n", average);
  printf("The maximum value is %d and the minimum value is %d\n\n", max, min);

  return;
}