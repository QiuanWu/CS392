/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char *my_strcat(char *dst, char *src) {

	//Copies src onto the end of dst and returns dst
 	//Does not allocate memory
 	//Assumes there is enough memory allocated in dst to hold both strings
 	//Overwrites src's original '\0' and places a new '\0' onto the end

	if(src != NULL && dst != NULL) {

		int i = 0;
		while(dst[i] != '\0') {
			++i;
		}

		int j = 0;
		int len = my_strlen(src);
		while(j < len){
			dst[i] = src[j];
			++i;
			++j;
		}

		dst[i] = '\0'; 	
	}
	
	return dst;
}