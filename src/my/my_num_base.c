/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

void my_num_base(int num, char* str) {

  int i = 0;
  int length = my_strlen(str);

  if (str == NULL || length == 0) {
      my_str("The argument is invalid: NULL or Empty.");
  } 

  else {

    int sign = -1;

      if (num >= 0) {
        num = num * -1;
      } else {
          my_char('-');
      }

      if (num == 0) {
          if(length == 1) {
              return;
          } else {
              my_char(str[0]);
          }
      } 

      else if (length == 1) {
          for (i = 0; i > num; i--) {
              my_char(str[0]);
          }
      } 

      else {
          while (sign >= num / length) {
              sign = sign * length;
          }
          
          while(num < 0 || sign < 0) {
              my_char(str[num / sign]);
              num = num % sign;
              sign = sign / length;
          }
      }
   }
  
}


