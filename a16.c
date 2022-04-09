/******************************************************************************

This program reads a file named "a16.dat" and calculates the average of
all the integer numbers written in the file

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#include <limits.h>

int main () {
  FILE* sp_input;
  float average;
  int count;
  int minimum_value = INT_MAX;
  int maximum_value = INT_MIN;
  sp_input = fopen("a16.dat", "r");

  if (sp_input == NULL)
    printf("Unable to open the file a16.dat\n");
  else {
    int num;
    count = 0;
    while(fscanf(sp_input, "%d\n", &num) != EOF) {
      if(minimum_value > num)
        minimum_value = num;
      if(maximum_value < num)
        maximum_value = num;
      average += num;
      count += 1;
    }
    average /= count;
    fclose(sp_input);
  }

  printf("\nThe average of the %d numbers is %f\n", count, average);
  printf("the maximum value is %d and the minimum value is %d\n", maximum_value, minimum_value);

  return 0;
}