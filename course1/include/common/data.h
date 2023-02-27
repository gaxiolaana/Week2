/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * This header file provides basic data manipulation
 * functions (integer to ASCII and ASCII to integer)
 *
 * @author Ana Gaxiola 
 * @date December 20, 2022
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <memory.h>
#include <stdint.h>
#include <math.h>
/**
 * @brief Converts a ASCII string/char to int
 *
 * Converts data back from an ASCII represented 
 * string into an integer type.
 *
 * @param ptr Pointer to ASCII character
 * @param digits Number of digits in the character
 * @param base conversion base (2 to 16)
 *
 * @return int32_t.
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief Converts integer to ASCII string/char
 *
 * Converta data from a standard integer type into an ASCII string.
 *
 * @param data Interger to be converted to ASCII character
 * @param ptr  converted character string 
 * @param base conversion base (2 to 16)
 *
 * @return int8_t.
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
#endif /* __DATA_H__ */
