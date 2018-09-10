/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"


int my_strrindex(char* arr, char letter)  {
  int index = my_strlen(arr) - 1;

  if(index == -2) {

    return -1;
  }

  else {

    while(index >= 0 && arr[index] != letter) {
      
      --index;
    }
    
  return index;
  }
}

