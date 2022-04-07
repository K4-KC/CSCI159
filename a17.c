/******************************************************************************

This program encodes and decodes messages by reading and writing
into a file

Author: Kanva Kanva

*******************************************************************************/

#include <stdio.h>

void get_choice_and_key(int *choice, int *key);
void encode(int key);
void decode(int key);

/************************************************************************/

int main() {
  int choice;
  int key;

  get_choice_and_key(&choice, &key);

  switch(choice) {
    case 1: {
      encode(key);
      break;
    }

    case 2: {
      decode(key);
      break;
    }

    default:
      printf("Something is wrong with the function get_choice_and_key()");
  }

  return 0;
}

/************************************************************************/

//This function gets the choice and key from the user
void get_choice_and_key(int *choice, int *key) {
  do {
    printf("Enter 1 to encrypt or 2 to de-encrypt: ");
    scanf("%d", &*choice);
  } while(*choice != 1 && *choice != 2);
  printf("\n");

  do {
    printf("Enter the key (from 0 to 10 inclusive): ");
    scanf("%d", &*key);
  } while(*key < 0 || *key > 10);
  printf("\n");

  return;
}

/************************************************************************/

//This function encodes the msg file and writes it into e_msg
void encode(int key) {
  FILE* f_input;
  FILE* f_output;
  char c;
  f_input = fopen("msg", "r");
  if(f_input == NULL) {
    printf("Failed to read msg file\nexiting...\n\n");
    return;
  }

  f_output = fopen("e_msg", "w");

  while((c = fgetc(f_input)) != EOF)
    fputc(c + key, f_output);

  printf("The file 'msg' has been encrypted as 'e_msg'.\n\n");

  return;
}

/************************************************************************/

//This function decodes e_msg and writes the decoded message into d_msg
void decode(int key) {
  FILE* f_input;
  FILE* f_output;
  char c;
  f_input = fopen("e_msg", "r");
  if(f_input == NULL) {
    printf("Failed to read e_msg file\nexiting...\n\n");
    return;
  }

  f_output = fopen("d_msg", "w");

  while((c = fgetc(f_input)) != EOF)
    fputc(c - key, f_output);

  printf("The file 'e_msg' has been de-encrypted as 'd_msg'.\n\n");

  return;
}
