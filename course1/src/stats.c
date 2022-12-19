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
 * @file stats.c
 * @brief This file test the functionality of stats.h by calculating the mean, median, max
 * and min vaues of a unsigned char n-element data array.
 * 
 *
 * @author Ana Gaxiola
 * @date 19.10.2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned int mean;
  unsigned int median;
  unsigned int max;
  unsigned int min;

  /* Statistics and Printing Functions Go Here */
  sort_array(test,SIZE);
  print_array(test,SIZE); //To check it was correctly sorted
  max = find_maximum(test);
  min = find_minimum(test,SIZE);
  mean = find_mean(test,SIZE);
  median = find_median(test,SIZE);
  print_statistics(mean, median, max, min);
}

/* Add other Implementation File Code Here */
