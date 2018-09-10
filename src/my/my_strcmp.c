/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

int my_strcmp(char *a, char *b){
	//Compares strings by ascii value.If a and b are identical, return 0. 
	//if a < b, return negative number, if a > b, return positive number
	//Two NULL are equal. NULL is always less than a normal string

	unsigned int n = 0;
	unsigned int l1 = my_strlen(a);
	unsigned int l2 = my_strlen(b);

	if(a != NULL && b != NULL) {
		unsigned int i;
		for(i = 0; i < l1 && i < l2 && n == 0; i++)
			n = a[i] - b[i];

		if(n == 0 && i < l1)
			n = 1;

		else if(n == 0 && i < l2)
			n = -1;		
	}
	else if(a == NULL && b == NULL) {
		return 0;
	}
	else if (a == NULL && b != NULL) {
		return -1;
	}
	else if (a != NULL && b == NULL) {
		return 1;
	}

	return n;
}
