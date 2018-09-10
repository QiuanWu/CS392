/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

int my_revstr(char* str) {
  
  int first = 0;
  int last = my_strlen(str) - 1;

  if (str == NULL) {
    return -1;
  }
                   
  while (! (first >= last)) {
    char f = str[first];
    char l = str[last];
    *(str + first) = l;
    *(str + last) = f;
    first++;
    last--;
  }

  return my_strlen(str);
}

