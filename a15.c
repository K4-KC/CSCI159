/******************************************************************************

This program uses a recursive function to calculate the power of a float
value and prints it out with an encouraging message

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

int get_input(float *num, int *exp);
float recur_pow(float num, int exp);
void print_output(float num, int exp, float result, int attempts);

/************************************************************************/

int main()
{
  float num;
  int exp;
  float result;
  int attempts;

  attempts = get_input(&num, &exp);
  result = recur_pow(num, exp);              	
  print_output(num, exp, result, attempts);

  return 0;
}

/************************************************************************/

int get_input(float *num, int *exp) {
  int attempts = 0;
  do {
    printf("Enter the real number (from -10.0 to +10.0, excluding 0.0): ");
    scanf("%f", &*num);
    attempts += 1;
  } while(*num > 10 || *num < -10);
  
  do {
    printf("Enter the integer exponent (from 0 to 9): ");
    scanf("%d", &*exp);
    attempts += 1;
  } while(*exp > 9 || *exp < 0);
  
  printf("\n");
  
  return attempts;
}

/************************************************************************/

float recur_pow(float num, int exp) {
  if(exp <= 0)
    return 1;
  else
    return num * recur_pow(num, exp-1);
}

/************************************************************************/

void print_output(float num, int exp, float result, int attempts) {
  printf("%0.2f^%d is %0.2f By the way...\n", num, exp, result);
  
  switch(attempts) {
    case 2:
      printf("you follow directions well!\n\n");
      break;
    case 3:
    case 4:
    case 5:
      printf("you need to pay more attention!\n\n");
      break;
    default:
      printf("you are hopeless!\n\n");
  }
  
  return;
}
