/******************************************************************************

This program prints a bunch of numbers as a table in the descending order
using three different kinds of loops

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

int main() {
  int num;
  int num_value;
  int line_count;
  printf("\nEnter an integer between 1 and 100: ");
  scanf("%d", &num);

  if(num > 100)
    num = 100;

  num_value = num;
  line_count = 0;
  printf("\nwhile loop:\n");
  while(num_value > 0) {
    if(line_count < 10)
      line_count++;
    else {
      printf("\n");
      line_count = 1;
    }
    printf("%4d", num_value);
    num_value--;
  }
  printf("\n");

  num_value = num;
  line_count = 0;
  printf("\ndo-while loop:\n");
  do {
    if(line_count < 10)
      line_count++;
    else {
      printf("\n");
      line_count = 1;
    }
    printf("%4d", num_value);
    num_value--;
  } while(num_value > 0);
  printf("\n");

  num_value = num;
  line_count = 0;
  printf("\nfor loop:\n");
  for(int num_value = num; num_value > 0; num_value--) {
    if(line_count < 10)
      line_count++;
    else {
      printf("\n");
      line_count = 1;
    }
    printf("%4d", num_value);
  }
  printf("\n\n");

  return 0;
}