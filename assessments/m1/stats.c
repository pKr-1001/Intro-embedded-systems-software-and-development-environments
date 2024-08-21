/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief < main has 40 characters for testing. Functions for providing statistics of an array >
 * 
 *
 * @author <Seung Min Park>
 * @date <Aug 19 2024 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char *arr, unsigned int size);
void print_array(unsigned char *arr, unsigned int size);
void find_median(unsigned char *arr, unsigned int size);
void find_mean(unsigned char *arr, unsigned int size);
void find_maximum(unsigned char *arr, unsigned int size);
void find_minimum(unsigned char *arr, unsigned int size);
void sort_array(unsigned char *arr, unsigned int size);

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_statistics(test, SIZE);
  // print_array(test, SIZE);
  // find_median(test, SIZE);
  // find_mean(test, SIZE);
  // find_maximum(test, SIZE);
  // find_minimum(test, SIZE);
  // sort_array(test, SIZE);

  return 0;
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *arr, unsigned int size){
  print_array(arr, size);
  find_median(arr, size);
  find_mean(arr, size);
  find_maximum(arr, size);
  find_minimum(arr, size);
  sort_array(arr, size);
}

void print_array(unsigned char *arr, unsigned int size){
  printf("Printing an array: ");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}


void find_median(unsigned char *arr, unsigned int size){
  // sort the array
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size - 1; j++){
      if(arr[j] > arr[j+1]){
        unsigned char temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  unsigned char median;
  if(size % 2 == 0){
    median = (arr[size/2] + arr[size/2 - 1]) / 2;
  } else {
    median = arr[size/2];
  }

  printf("Median: %d\n", median);
}

void find_mean(unsigned char *arr, unsigned int size) {
  unsigned int sum = 0;
  for(int i = 0; i < size; i++){
    sum += arr[i];
  }

  printf("Mean: %d\n", sum / size);
}

void find_maximum(unsigned char *arr, unsigned int size){
  unsigned char max = 0;

  for(int i = 0; i < size; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }

  printf("Maxmimum: %d\n", max);
}

void find_minimum(unsigned char *arr, unsigned int size){
  unsigned char min = 255;

  for (int i = 0; i < size; i++){
    if (arr[i] < min){
      min = arr[i];
    }
  }

  printf("Minimum: %d\n", min);
}

void sort_array(unsigned char *arr, unsigned int size){
  // sorting the array from largest to smallest
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size - 1; j++){
      // if current element is smaller, swap
      if(arr[j] < arr[j+1]){
        unsigned char temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("Sorted array: ");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}
