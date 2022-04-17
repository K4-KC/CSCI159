/******************************************************************************

This program reads a file named "a16.dat" and can calculate the average,
maximum, minimum score or prints out a list of scores.

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#define MAX_NUMBER_OF_STUDENTS 25


void test_avg(float* avg, int test[], int size);
void test_max_min(int* max, int* min, int test[], int size);
void print_test(int test[], int size);
int menu();
int get_test_scores(int test[], int* number_of_students);

/************************************************************************/

int main() {

  int choice, max, min;
  float avg;
  int test[MAX_NUMBER_OF_STUDENTS];
  int file_opened;
  int number_of_students;

  file_opened = get_test_scores(test, &number_of_students);

  if (file_opened == 0) {
    do {
      choice = menu();
      switch (choice) {
        case 0: printf("\nProgram is over.\n");
          break;
        case 1: test_avg(&avg, test, number_of_students);
          printf("\nAverage score on test = %5.2f\n", avg);
          break;
        case 2: test_max_min(&max, &min, test, number_of_students);
          printf("\nMaximum score = %3d\n"
              "Minimum score = %3d\n", max, min);
          break;
        case 3: print_test(test, number_of_students);
          break;
        default:
          printf("This should never happen!");
      }

    } while (choice != 0);
  }

  return 0;
}

/************************************************************************/

// Reads the test scores from a20.dat file
int get_test_scores(int test[], int* number_of_students) {

  FILE* in_file;
  int i;

  in_file = fopen("a20.dat", "r");

  if(in_file == NULL) {
    printf("There was an error reading the a20.dat file.\nProgram terminated\n");
    return 1;
  } else {
    i = 0;
    while(fscanf(in_file, "%d", &test[i]) != EOF)
      i++;
    *number_of_students = i;

    fclose(in_file);

    return 0;
  }
}

/************************************************************************/

// Prints the main menu to choose what the program must do
int menu() {

  int choice;

  do {
    choice = -1;
    printf("\nEnter your choice:\n");
    printf("0 Quit  1 Test Average  2 Test Max/Min  3 Print Scores: ");
    scanf("%d", &choice);
    getchar();
  } while(choice != 0 && choice != 1 && choice != 2 && choice != 3);

  return choice;
}

/************************************************************************/

// Calculates and prints avg score
void test_avg(float* avg, int test[], int size) {
  
  int sum = 0;
  for(int i = 0; i < size; i++)
    sum += test[i];
  
  *avg = (float)sum / size;

  return;
}

/************************************************************************/

// Calculates and prints max and min scores
void test_max_min(int* max, int* min, int test[], int size) {

  *max = 0;
  *min = 100;
  for(int i = 0; i < size; i++) {
    if(test[i] > *max)
      *max = test[i];
    if(test[i] < *min)
      *min = test[i];
  }

  return;
}

/************************************************************************/

// This function prints the list of scores
void print_test(int test[], int size) {

  printf("\nStudent #  Score\n");

  for(int i = 0; i < size; i++) {
    printf("%2d    %3d\n", i + 1, test[i]);
  }

  return;
}