/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

 #include "../../include/my.h"

int my_atoi(char* n){

	//Returns the int represented by the ascii string
 	//Handles negatives.
 	//Ignores preceding characters and trailing numbers and chars
 	//Examples:
 	//"5" => 5
 	//"-5" => -5
 	//"--5" => 5
 	//"a-b54sc7-d" => -54
 	//"abcd" => 0
  //NULL => 0

	long int num = 0;
  int flag = 0;
  int p = 1;

  if (n != NULL) {

    	for (;*n;n++) {
          p = (*n == '-') ? (p * -1) : p;

      	  if (*n < '0' || *n > '9') {
        
              if (flag) {
                  break;
        	    }
      	  }

      	  else {

        	    num = (num * 10) + ((*n) - '0');
        	    flag = 1;

          }
        }
    }

    return (int)num*p;

}
