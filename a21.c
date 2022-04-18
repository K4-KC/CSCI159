#include <stdio.h>
#include <math.h>

int get_array(float array[], int* size );
float average(float array[], int  size);         
float median(float array[], int size);         
void bubble_sort(float array[], int size);   
void swap(float* num1, float* num2);
void print_results(int size, float avg, float median);
void print_error_msg(void);

int main() {
  float array[50];
  float avg;
  float med;
  int size;

  if(get_array(array, &size) == 0) {
    avg = average(array, size);
    med = median(array, size);
    print_results(size, avg, med);
  } else
    print_error_msg();

  return 0;
}

int get_array(float array[], int* size) {
  FILE* sp_input;
  int i;
  i = 0;
  if((sp_input = fopen("a21.dat","r")) != NULL) {
    while ((fscanf(sp_input, "%f", &array[i])) != EOF)
      i++;

    fclose(sp_input);
    *size = i;
    return 0;
  } else
    return 1;
}

float average(float array[], int size) {
  int i;
  float sum;

  sum = 0;
  for (i = 0; i < size; i++)
    sum = sum + array[i];

  return sum/size;
}

void bubble_sort(float array[], int size) {
  int index_after_wall;
  int walk;
  
  for (index = 0; index < size; index++) {
    for (walk = size - 1; walk > index; walk--) {
      if (a[walk] < a[walk - 1])
          swap(&a[walk], &a[walk - 1]);
     }
  }
  return;
}

void swap(float* num1, float* num2) {
  float temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
  return;
}

float median(float array[], int size) {
  
  float med;
  
  bubble_sort(array, size);

  med = (array[floor((float) size / 2)] + array[ceil((float) size / 2)]) / 2;
  
  return med;
}

void print_results(int size, float avg, float median) {
  printf("\nThe average was %.2f and the median was %.2f "
           "for the %d numbers processed\n", avg, median, size);
  return;
}

void print_error_msg() {
  printf("\nThere was a problem with openning the file."
         "\nI'm so sorry things didn't work out as you had planned.\n");
  return;
}
