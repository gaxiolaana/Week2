#include "data.h"


/**
 * @file data.c
 * @brief Basic data manipulation
 *
 * This c file provides basic data manipulation
 * functions (integer to ASCII and ASCII to integer)
 *
 * @author Ana Gaxiola 
 * @date December 20, 2022
 *
 */
 
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
   int32_t num = abs(data);
   uint8_t digits_cnt=0;
   uint8_t sign=0;
   uint8_t digit=0;


   if (data < 0){
      *ptr = '-';
      ptr++;
      sign = 1;
   }


   while(num != 0){
      digit = num%base;

      // Digit acc. to ascii table
      if (base==16 && (digit >= 10)){
         digit = (num%base) + 7;
      }

      num = num/base;
      digits_cnt++;
      *ptr = '0' + digit;
      ptr++;
   }
   *ptr = '\0';
   
   /*Point to the begin to reverse*/      
   for(uint8_t n=0; n<digits_cnt; n++){
      ptr--;
   }

   /*Reverse only digits*/
   my_reverse(ptr,digits_cnt);
 
    /*point to sign*/
   if (sign == 1){
      ptr--;
   }
   
   return digits_cnt + sign + 1;
 }

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
   int32_t number = 0;
   int32_t int_char;
   int32_t sign = 1;
   //take into account that digits include '/0'
   digits--;
   
   //check negative
   if (*ptr == '-'){
      sign = -1;
      ptr++;
      digits--;
   }

   for(uint8_t n=digits; n>0; n--){
      int_char = (*ptr-0);
      if (base == 16 && int_char >= 65){
         number += (int_char-55);
      }
      else{
         number += (int_char-48)*pow(base,(n-1));
      }
      ptr++;
   }
      
   return number*sign;
}
