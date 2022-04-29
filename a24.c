/******************************************************************************

This program reads a file named "a24.dat" with records of names
and IDs and sorts the list according to both the names and ID numbers
and prints it out.

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_RECORDS 25 

// Structure
typedef struct {
  char last[10];
  char first[10];
  int age;
  int id;
} PERSONAL_INFO;

int get_info(PERSONAL_INFO array[], int* records);
void print_info_name(PERSONAL_INFO array[], int records);
void print_info_id(PERSONAL_INFO array[], int records);
void sort_by_id(PERSONAL_INFO array[], int records);
void sort_by_name(PERSONAL_INFO array[], int records);
void swap(PERSONAL_INFO* a, PERSONAL_INFO* b);

/************************************************************************/

// Main function
int main(void) {

  PERSONAL_INFO array[MAX_RECORDS];
  int records;

  if (get_info(array,&records) == 0) {
    printf("\nOriginal order:");
    print_info_name(array, records);
    sort_by_name(array, records);
    printf("\n\nAlphabetical order:");
    print_info_name(array, records);
    sort_by_id(array, records);
    printf("\n\nID number order:");
    print_info_id(array, records);
    printf("\n\n");
  } else
    printf("\nThere was a problem\n\n");

  return 0;
}

/************************************************************************/

// Reads information from a24.dat file
int get_info(PERSONAL_INFO array[], int* records) {

  FILE* in_file;
  int i;

  in_file = fopen("a24.dat", "r");

  if(in_file == NULL) {
    return 1;
  } else {
    i = 0;
    while(fscanf(in_file, "%s %s %d %d",
      array[i].last, array[i].first, &array[i].age, &array[i].id) != EOF)
      i++;
    *records = i;

    fclose(in_file);

    return 0;
  }
}

/************************************************************************/

// prints information with last name being the priority
void print_info_name(PERSONAL_INFO array[], int records) {
  for(int i = 0; i < records; i++)
    printf("\n%-10s %-10s %4d %6d", array[i].last, array[i].first, array[i].age, array[i].id);
  
  return;
}

/************************************************************************/

// prints information with ID being the priority
void print_info_id(PERSONAL_INFO array[], int records) {
  for(int i = 0; i < records; i++)
    printf("\n%6d %-10s %-10s %4d", array[i].id, array[i].last, array[i].first, array[i].age);
  
  return;
}

/************************************************************************/

// sorts the array according to ID numbers
void sort_by_id(PERSONAL_INFO array[], int records) {
  int i, j;
  for(i = 0; i < records; i++) {
    for(j = records - 1; j > 0; j--) {
      if(array[j].id < array[j - 1].id)
        swap(&array[j], &array[j - 1]);
    }
  }
  
  return;
}

/************************************************************************/

// sorts array according to the last name
void sort_by_name(PERSONAL_INFO array[], int records) {
  int i, j;
  for(i = 0; i < records; i++) {
    for(j = records - 1; j > 0; j--) {
      if(strcmp(array[j].last, array[j - 1].last) < 0)
        swap(&array[j], &array[j - 1]);
    }
  }
  
  return;
}

/************************************************************************/

// swap function
void swap(PERSONAL_INFO* a, PERSONAL_INFO* b) {
  PERSONAL_INFO temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}
