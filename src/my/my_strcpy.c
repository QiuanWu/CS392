/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char *my_strcpy(char *dst, char *src) {

	//Copies the characters from src into dst overwriting what's already in there.
 	//Always copies a '\0'
 	//Assumes dst has enough memory allocated for the new string if it is longer.
 	//Does not allocate memory

	if(src != NULL && dst != NULL) {

		int i = 0;

		while(src[i] != '\0') {

			dst[i] = src[i];
			++i;
		}

		dst[i] = '\0';
	}

	return dst;

}