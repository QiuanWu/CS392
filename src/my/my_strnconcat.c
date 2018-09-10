/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char *my_strnconcat(char *a, char *b, int n) {
  
  //Allocates new memory
  //Copies all of a and then n chars or length of b
  //returns pointer to new string
  

  char *ns;
  if (a != NULL && b != NULL) {

    ns = malloc(my_strlen(a) + my_strlen(b)+1);

  }
  else if (a == NULL && b != NULL) {

    ns = malloc(my_strlen(b)+1);

  }
  else if (a != NULL && b == NULL) {

    ns = malloc(my_strlen(a)+1);

  }
  else {

    return NULL;

  }

  int i = 0;
  if (a != NULL) {

    for (;*a;a++,i++) {
      ns[i] = *a;
    }

  }
  if (b != NULL) {

    for (;*b && n>0;b++,n--,i++) {
      ns[i] = *b;
    }

  }

  ns[i] = '\0';
  return ns;
  
}
