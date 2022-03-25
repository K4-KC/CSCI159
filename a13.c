/******************************************************************************

This program prints a bunch of numbers in a pattern with nested for loops

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

int get_input();
void produce_output(int num);

/************************************************************************/

int main(void) {
  int num;
  num = get_input();
  produce_output(num);
  return 0;
}

/************************************************************************/

int get_input() {
  int num;
  while(num < 0 || num > 30) {
    printf("\nEnter the number (between 0 and 30 inclusive): ");
    scanf("%d", &num);
  }

  return num;
}

/************************************************************************/

void produce_output(int num) {
  for(int i = num; i >= 0; i--) {
    for(int j = i; j >= 0; j--) {
      printf("%2d ", j);
    }
    printf("\n");
  }
  return;
}