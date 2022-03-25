/******************************************************************************

This program calculates the approximate value of e raised to power of x
using a series of terms

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

float fpow(float base, int ex);
int fact(int num);
void get_input(float *x, int *num_terms);
float e_to_the_x(float x, int num_terms);
void print_output(float x, float result);

/************************************************************************/

int main()
{
  float x;
  float result;
  int num_terms;
    
  get_input(&x, &num_terms);
    
  result = e_to_the_x(x, num_terms);
    
  print_output(x, result);

  return 0;
}

/************************************************************************/

float fpow(float base, int ex) {
  float result = 1;
  for(int i = 0; i < ex; i++) 
    result *= base;
    
  return result;
}

/************************************************************************/

int fact(int num) {
  int result = 1;
  for(int i = 1; i <= num; i++)
    result *= i;
    
  return result;
}

/************************************************************************/

void get_input(float *x, int *num_terms) {
  printf("Enter the power to which e is to be raised: ");
  scanf("%f", *&x);
  printf("Enter the desired number of terms (from 1 to 12 inclusive): ");
  scanf("%d", *&num_terms);
    
  return;
}

/************************************************************************/

float e_to_the_x(float x, int num_terms) {
  float result = 0;
    
  for(int i = 0; i < num_terms; i++)
    result += fpow(x, i)/fact(i);
    
  return result;
}

/************************************************************************/

void print_output(float x, float result) {
  printf("e^ %0.2f is %0.6f\n\n", x, result);
}