/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"


int my_strlen(char* str) {
	int count = 0;

	if (&str[0] == NULL) {
		return -1;
	}

	for (int i = 0; str[i] != '\0'; i++) {
		count = count + 1;
	}

	return count;
}
