/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

char *my_strdup(char *str) {

	//Allocates new memory 
 	//Copies str into that new memory 
 	//returns pointer to new string

	unsigned int l = my_strlen(str);

	if(str != NULL) {

		char *result = (char*)malloc((l + 1)*sizeof(char));
		result = my_strcpy(result,str);
		return result;

	}

	else {

		return NULL;
		
	}
}
