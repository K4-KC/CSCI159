/******************************************************************************

This program will convert polar
polar coordinates to rectangular coordinates or
rectangular coordinates to polar coordinates

Author: Kanva K

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HI 1
#define LO 2
#define INITIAL 3
#define MATCH 0

int random_number();
void intro_message();

void get_guess(int* guess, int result);

int check_guess(int guess, int number);

void exit_message(int result, int number);

/************************************************************************/

int main(void) {
    int guess;
    int number;
    int result;

    number = random_number();
    intro_message();
    get_guess(&guess, INITIAL);
    result = check_guess(guess,number);

    if (result != MATCH) {
        get_guess(&guess, result);
        result = check_guess(guess, number);
    }

    if (result != MATCH) {
        get_guess(&guess, result);        result = check_guess(guess, number);
        }

    if (result != MATCH) {
        get_guess(&guess, result);
        result = check_guess(guess, number);
    }

    if (result != MATCH) {
        get_guess(&guess, result);
        result = check_guess(guess, number);
    }

    exit_message(result, number);

    return 0;
}

/************************************************************************/

int random_number() {
    int t = time(NULL);
    srand(t);

    return rand()%20;
}

/************************************************************************/

void intro_message() {
    printf("Try to guess a number between 0 and 20.\n\n");

    return;
}

/************************************************************************/

void get_guess(int* guess, int result) {
    switch(result) {
        case INITIAL:
            printf("Enter your guess: ");
            break;

        case 1:
            printf("Your guess is too high. Guess again: ");
            break;

        case 2:
            printf("Your guess is too low. Guess again: ");
            break;
        
        default:
            printf("This is not supposed to happen. Your code is incredibly stupid.");
    }

    scanf("%d", &*guess);
    printf("\n");

    return;
}

/************************************************************************/

int check_guess(int guess, int number) {
    int result;
    if(guess > number) {
        result = 1;
    } else if(guess < number) {
        result = 2;
    } else {
        result = 0;
    }

    return result;
}

/************************************************************************/

void exit_message(int result, int number) {
    if(result == MATCH) {
        printf("You're a genius! You have guessed the number!\n\n");
    } else {
        printf("You baboon! You've failed miserably!\n\n");
    }

    return;
}