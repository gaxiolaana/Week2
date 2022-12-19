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
 * @file stats.h
 * @brief This file contains all the necessary funtions to calculate data statistics.
 *
 * This file contains 6 functions to caculate and print the median, mean, max and min 
 * values of a given unsigend char n-element data array.
 *
 * @author Ana Gaxiola
 * @date 19.10.2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Function declaration */ 

/**
 * @brief This function prints the statistics of an array to the console.
 *
 * This funtion calls methods to calculate the minimum, maximum, mean, and median
 * values of an array and prints them out to the console.
 *
 *Functions are declare and coded.
 
 * @param mean An unsigned integer representing the mean
 * @param median An unsigned integer representing the median
 * @param max An unsigned integer representing the max value
 * @param min An unsigned integer representing the min value
 * @return void (prints out to the console)
 */

void print_statistics(unsigned int mean,unsigned int median,unsigned int max, unsigned int min){
    printf("The mean is: %u\n", mean);
    printf("The median is: %u\n", median);
    printf("The maximum value is: %u\n", max);
    printf("The minimum value is: %u\n", min);
}

/**
 * @brief This function prints a given array to the console.
 *
 * Given an array and its size, this funtion reads the arrays values
 * and prints them out to the console.
 *
 * @param data A unsigned char pointer to an n-element data array
 * @param size An unsigned integer representing the size of the array
 *
 * @return void (prints out to the console)
 */

void print_array(unsigned char data[], unsigned int size){
    printf("The data is:\n");
    for (int i = 0; i < size; i++){
        printf("%d\n", *data);
        data++;
    }

}

/**
 * @brief This funtion swap two variables values by accesing their address.
 *
 * Given two variables, their values are swapted by accesing their address and
 * using a temporary variable.
 *
 * @param a A pointer to an unsigned char variable
 * @param b A pointer to an unsigned char variable 
 */
//Funtion to swap values
void swap(unsigned char *a, unsigned char *b){
    unsigned char temp = *a;
    *a = *b;
    *b = temp;    
}


/**
 * @brief This funtion sort an array from its largest to smallest element.
 *
 * Given an array of data and its size,  sorts the array from largest to smallest.
 * (The zeroth Element is the largest value, and the last element (n-1) 
 * is the smallest value.)
 *
 * @param data An unsigned char n-element data array
 * @param size An unsigned integer representing the size of the array
 *
 */

void sort_array(unsigned char data[], unsigned int size){
    int i,j;
    unsigned int a,b;
    for(i = 0; i < size; i++){
        for(j = 0; j < (size-1); j++){
            if (data[i] > data[j]){
                swap(&data[j],&data[i]);
            }
        }
    }
}

/**
 * @brief This funtion returns the median value of an array.
 *
 * Given an array of data and its size, returns the median value. For this,
 * the array must be sorted in descending order and then the median is calculated.
 *
 * @param data An unsigned char n-element data array sorted is descending order.
 * @param size An unsigned integer representing the size of the array
 *
 * @return median as unsigned integer 
 */

unsigned int find_median(unsigned char data[], unsigned int size){
    int index = size/2;
    if ((size%2) == 0){
        return (((unsigned int)data[index-1] + (unsigned int)data[index]) / 2); 
    }
    else{
        return (unsigned int)data[index];
    }
}


/**
 * @brief This funtion returns the mean value of an array.
 *
 * Given an array of data and its size, returns the mean value. For this,
 * all the values of the array are summed up and the result is divided by the array's size.
 *
 * @param data An unsigned char pointer to an n-element data array
 * @param size An unsigned integer representing the size of the array
 *
 * @return mean as unsigned integer 
 */

unsigned int find_mean(unsigned char *data, unsigned int size){
    int i;
    unsigned int sum = 0;
    for (i=0; i< size; i++){
        sum += *data;
        data++;
    }
    return (sum/size);
}

/**
 * @brief This funtion returns the maximum value of an array.
 *
 * Given an array of data (sorted in descending order) returns the maximum value. For this,
 * the array must be sorted in descending order where the zero-index element is the
 * maximum one.
 *
 * @param data An unsigned char n-element data array sorted is descending order.
 *
 * @return maximum value as unsigned integer 
 */

unsigned int find_maximum(unsigned char data[]){
    return data[0];
}


/**
 * @brief This funtion returns the minimum value of an array.
 *
 * Given an array of data (sorted in descending order) and its size returns the minimum value. For this,
 * the array must be sorted in descending order where the [size -1] index element is the
 * maximum one.
 *
 * @param data An unsigned char n-element data array sorted is descending order.
 * @param size An unsigned integer representing the size of the array
 *
 * @return maximum value as unsigned integer 
 */

unsigned int find_minimum(unsigned char data[], unsigned int size){
    return data[size-1];
}

#endif /* __STATS_H__ */
