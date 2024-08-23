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
 * @file <stats.h> 
 * @brief <header file >
 *
 *
 * @author <Seung Min Park>
 * @date <Aug 19 2024 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */



/**
 * @brief <Prints the statistics of an array including minimum, maximum, mean, and median.>
 * 
 * @param <arr> <The array to find the statistics>
 * @param <size> <The size of the array>
*/

void print_statistics(unsigned char *arr, unsigned int size);


/**
 * @brief <Given an array of data and a length, prints the array to the screen>
 * 
 * @param <arr> <The array to be printed>
 * @param <size> <The size of the array>
*/
void print_array(unsigned char *arr, unsigned int size);

/**
 * @brief <Given an array of data and a length, returns the median value>
 * 
 * @param <arr> <The array to find the median value>
 * @param <size> <The size of the array>
*/

void find_median(unsigned char *arr, unsigned int size);

/**
 * @brief <Given an array of data and a length, returns the mean value>
 * 
 * @param <arr> <The array to find the mean value>
 * @param <size> <The size of the array>
*/

void find_mean(unsigned char *arr, unsigned int size);

/**
 * @brief <Given an array of data and a length, returns the maximum value>
 * 
 * @param <arr> <The array to find the maximum value>
 * @param <size> <The size of the array>
*/

void find_maximum(unsigned char *arr, unsigned int size);

/**
 * @brief <Given an array of data and a length, returns the minimum value>
 * 
 * @param <arr> <The array to find the minimum value>
 * @param <size> <The size of the array>
*/

void find_minimum(unsigned char *arr, unsigned int size);

/**
 * @brief <Given an array of data and a length, sorts the array from largest to smallest.>
 * 
 * @param <arr> <The array to be sorted>
 * @param <size> <The size of the array>
*/

void sort_array(unsigned char *arr, unsigned int size);


#endif /* __STATS_H__ */
