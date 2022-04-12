/******************************************************************************

This program takes two arrays as input and adds them and prints them out.

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

int get_input();
void get_array(float array[], int size, int array_number);
void add(float a1[], float a2[], float sum[], int size);
void out_put(float array1[], float array2[], float sum[], int size);

int main(void)
{
  float a[10];
  float b[10];
  float sum[10];
  int size;

  size = get_input();

  get_array(a, size, 1);
  get_array(b, size, 2);
  add(a, b, sum, size);
  out_put(a, b, sum, size);

  return 0;
}

// Get size of array
int get_input() {
  int size;
  do {
    printf("\nEnter the size of the arrays (from 1 to 10 inclusive): ");
    scanf("%d", &size);
  } while (size < 1 || size > 10);
    
  return size;
}


// Get the values of array
void get_array(float array[], int size, int array_number) {
  printf("\nEnter the %d values for array%d: ", size, array_number);
  for(int i = 0; i < size; i++)
    scanf("%f", &array[i]);
    
  return;
}

// Add both the arrays
void add(float a1[], float a2[], float sum[], int size) {
  for(int i = 0; i < size; i++)
    sum[i] = a1[i] + a2[i];
    
  return;
}

// Print the sum of the arrays
void out_put(float array1[], float array2[], float sum[], int size) {
  printf("\narray1 array2 sum");
  for(int i = 0; i < size; i++)
    printf("\n%0.2f %0.2f %0.2f", array1[i], array2[i], sum[i]);
  printf("\n");
    
  return;
}
