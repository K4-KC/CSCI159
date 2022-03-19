/******************************************************************************

This program will sort three numbers
and print them out in order

Author: Kanva K

*******************************************************************************/

#include <stdio.h>

void get_values(int* a, int* b, int* c);
void swap(int* x, int* y);
void sorter(int* a, int* b, int* c);
void print_values(int a, int b, int c);

/************************************************************************/
int main(void)
{
  int a;
  int b;
  int c;

  get_values(&a, &b, &c);
  sorter(&a, &b, &c);
  print_values(a, b, c);

  return 0;
}

/************************************************************************/

void get_values(int* a, int* b, int* c) {
  printf("\nEnter the value for a: ");
  scanf("%d", &*a);
  printf("\nEnter the value for b: ");
  scanf("%d", &*b);
  printf("\nEnter the value for c: ");
  scanf("%d", &*c);

  return;
}

/************************************************************************/

void swap(int* x, int* y) {
  int z = *x;
  *x = *y;
  *y = z;

  return;
}

/************************************************************************/

void sorter(int* a, int* b, int* c) {
  if(*b < *c) 
    swap(&*b, &*c);
  if(*a < *b)
    swap(&*a, &*b);
  if(*b < *c)
    swap(&*b, &*c);

  return;
}

/************************************************************************/

void print_values(int a, int b, int c) {
  printf("\na = %d and b = %d and c = %d\n", a, b, c);

  return;
}