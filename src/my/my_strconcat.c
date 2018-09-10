/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

 #include "../../include/my.h"

char *my_strconcat(char *a, char *b) {

	//Allocates new memory 
 	//Copies concatenated strings in that new memory 
 	//Returns pointer to it
 	//If both NULL return NULL

	if (a == NULL && b == NULL) {

		return NULL;

	}
	if (a == NULL) {

		char* bd = my_strdup(b);
		return bd;

	}
	if (b == NULL) {

		char* ad = my_strdup(a);
		return ad;

	}
	else {

		char* ad = my_strdup(a);
		char* bd = my_strdup(b);
		my_strcat(ad,bd);
		return ad;

	}

}
