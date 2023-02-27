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


#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */
void print_statistics(unsigned int mean,unsigned int median,unsigned int max, unsigned int min){
    PRINTF("The mean is: %u\n", mean);
    PRINTF("The median is: %u\n", median);
    PRINTF("The maximum value is: %u\n", max);
    PRINTF("The minimum value is: %u\n", min);
}


void print_array(unsigned char data[], unsigned int size){
    #ifdef VERBOSE
    PRINTF("The data is:\n");
    for (int i = 0; i < size; i++){
	PRINTF("%d\n", *data);
	data++;
    }
    #endif
}

void swap(unsigned char *a, unsigned char *b){
    unsigned char temp = *a;
    *a = *b;
    *b = temp;    
}

void sort_array(unsigned char data[], unsigned int size){
    int i,j;
    for(i = 0; i < size; i++){
        for(j = 0; j < (size-1); j++){
            if (data[i] > data[j]){
                swap(&data[j],&data[i]);
            }
        }
    }
}

unsigned int find_median(unsigned char data[], unsigned int size){
    int index = size/2;
    if ((size%2) == 0){
        return (((unsigned int)data[index-1] + (unsigned int)data[index]) / 2); 
    }
    else{
        return (unsigned int)data[index];
    }
}

unsigned int find_mean(unsigned char *data, unsigned int size){
    int i;
    unsigned int sum = 0;
    for (i=0; i< size; i++){
        sum += *data;
        data++;
    }
    return (sum/size);
}

unsigned int find_maximum(unsigned char data[]){
    return data[0];
}

unsigned int find_minimum(unsigned char data[], unsigned int size){
    return data[size-1];
}

