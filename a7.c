/******************************************************************************

This program will convert polar
polar coordinates to rectangular coordinates or
rectangular coordinatest to polar coordinates

Author: Kanva K

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14159

void description();
int get_choice();
void get_polar_data(float *r, float *theta);
void get_rect_data(float *x, float *y);
void convert_to_rect(float r, float theta, float *x, float *y);
void convert_to_polar(float x, float y, float *r, float *theta);
void print_pr_result(float r, float theta, float x, float y);
void print_rp_result(float x, float y, float r, float theta);

/************************************************************************/

int main() {
  int choice;
  float r;
  float theta;
  float x;
  float y;

  description();
  choice = get_choice();

  if (choice == 1) {
    get_polar_data(&r, &theta);
    convert_to_rect(r, theta, &x, &y);
    print_pr_result(r, theta, x, y);
  } else {
    get_rect_data(&x, &y);
    convert_to_polar(x, y, &r, &theta);
    print_rp_result(x, y, r, theta);
  }

  return 0;
}

/************************************************************************/

void description() {
  printf("This program will convert\n");
  printf("polar coordinates to rectangular coordinates or\n");
  printf("rectangular coordinates to polar coordinates\n\n");

  return;
}

/************************************************************************/

int get_choice() {
  int choice;

  printf("Enter 1 for polar to rectangular\n");
  printf("Enter 2 for rectangular to polar\n");
  printf("\nYour choice: ");
  scanf("%d", &choice);

  return choice;
}

/************************************************************************/

void get_polar_data(float *r, float *theta) {
  printf("Enter the value for r (meters): ");
  scanf("%f", &*r);
  printf("Enter the value for theta (degrees): ");
  scanf("%f", &*theta);

  return;
}

/************************************************************************/

void get_rect_data(float *x, float *y) {
  printf("Enter the value for x (meters): ");
  scanf("%f", &*x);
  printf("Enter the value for y (meters): ");
  scanf("%f", &*y);

  return;
}

/************************************************************************/

void convert_to_rect(float r, float theta, float *x, float *y) {
  *x = r*cos(theta*PI/180);
  *y = r*sin(theta*PI/180);
  
  return;
}

/************************************************************************/

void convert_to_polar(float x, float y, float *r, float *theta) {
  *r = sqrt(x*x + y*y);
  *theta = atan(y/x)*180/PI;

  return;
}

/************************************************************************/

void print_pr_result(float r, float theta, float x, float y) {
  printf("\nr = %0.2f and theta = %0.2f\n", r, theta);
  printf("converts to\n");
  printf("x = %0.2f and y = %0.2f\n\n", x, y);

  return;
}

/************************************************************************/

void print_rp_result(float x, float y, float r, float theta) {
  printf("\nx = %0.2f and x = %0.2f\n", x, y);
  printf("converts to\n");
  printf("r = %0.2f and theta = %0.2f\n\n", r, theta);

  return;
}