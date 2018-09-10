/*******************************************************************************
 * Name        : Libmy2
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

int my_strncmp(char*a, char *b, int n){
	//Same as my_strcmp except:
 	//Only compares n chars or until the end of a string

	unsigned int num = 0;
	unsigned int l1 = my_strlen(a);
	unsigned int l2 = my_strlen(b);
	if(a != NULL && b != NULL) {
		unsigned int i;
		for(i = 0; i < l1 && i < l2 && i < n && num == 0; i++)
			num = a[i] - b[i];

		if(num == 0 && i < n && i < l1)
			num = 1;

		if(num == 0 && i < n && i < l2)
			num = -1;		
	}
	if(a == NULL && b == NULL) {
		return 0;
	}
	if (a == NULL && b != NULL) {
		return -1;
	}
	if (a != NULL && b == NULL) {
		return 1;
	}

	return num;
}
