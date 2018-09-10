/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char* my_strrfind(char* s, char c) {
	//Returns a pointer to the last char in the string which matches.
	//Return NULL if the letter is not found.
	
	if(my_strrindex(s, c) == -1) {
        return NULL;
    }
    else {
        return &s[my_strrindex(s, c)];
    }
}
	
