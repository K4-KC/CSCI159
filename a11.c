/******************************************************************************

This program converts base 10 numbers to binary

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>
#include <stdio.h>

int get_number();		
int ipow(int base, int exp);
void convert_to_binary(int n);

/************************************************************************/

int main(void) {
  int number;
  
  number = get_number();
  convert_to_binary(number);
  
  return 0;
}

/************************************************************************/

int get_number() {
  int number;
  do {
       printf("\nEnter the decimal number (from 0 to 1023):  ");
       scanf("%d", &number);
    } while(number > 1023 || number < 0);
  
  return number;
}

/************************************************************************/

int ipow(int base, int exp) {
  int p = 1;
  for(int i = 0; i < exp; i++) {
    p *= base;
  }
  
  return p;
}

/************************************************************************/

void convert_to_binary(int n) {
  for(int i = 9; i >= 0; i--) {
    int bin_dig = ipow(2, i);
    if(bin_dig <= n) {
      printf("1");
      n -= bin_dig;
    } else {
      printf("0");
    }
  }
  printf("\n");
  
  return;
}
