/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char *my_strncpy(char *dst, char *src, int n) {

	//Same as my_strcpy except:
 	//Only copies n chars or until the end of src

	if(src != NULL && dst != NULL) {

		int i = 0;

		while(src[i] != '\0' && i < n) {

			dst[i] = src[i];
			++i;
		}

		dst[i] = '\0';
	}

	return dst;
}
