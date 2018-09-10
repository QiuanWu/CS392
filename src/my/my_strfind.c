/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char* my_strfind(char* s, char c) {
    //Returns a pointer to the first char in the string which matches.
    //Return NULL if the letter is not found.
	
    if(c != '\0') {
      
       	while(s != NULL && *s != '\0') {

       		if(*s == c) {
            	return s;
			    }
            s++;
    	  }
    }
    return NULL;
}
