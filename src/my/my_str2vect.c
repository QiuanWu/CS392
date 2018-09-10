/*******************************************************************************
 * Name        : Minishell
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 03/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"

// Takes a string
// Allocates a new vector (array of string ended by a NULL),
// Splits apart the input string x at each space character
// Returns the newly allocated array of strings
// Any number of ' ','\t', and '\n's can separate words.
// I.e. "hello \t\t\n class,\nhow are you?" -> {"hello", "class,", "how", "are","you?", NULL}

char **my_str2vect(char *str) {

	int word_limit = 0;
	int char_limit = 0;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	while (str[x] != '\0') {

		if (str[x] != ' '  && str[x] != '\n' && str[x] != '\t') {
			++word_limit;
			++x;
			++y;
			while ((str[x] != ' ' && str[x] != '\n' && str[x] != '\t') && str[x] != '\0') {
				++x;
				++y;
			}
			if (y > char_limit) {
				char_limit = y;
			}
			y = 0;
			while ((str[x] == ' ' || str[x] == '\t' || str[x] == '\n') && str[x] != '\0') {
				++x;
			}
		}
	}

	char **result = (char **)malloc(sizeof(char *) * (word_limit + 1));
	for (int c = 0; c < word_limit + 1; ++c) {
		result[c] = (char *)malloc(sizeof(char) * (char_limit + 1));
	}
	while (i < my_strlen(str) && j < word_limit) {
		int k = 0;
		while (i < my_strlen(str) && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')) {
			++i;
		}
		while (i < my_strlen(str) && (!(str[i] == ' ' || str[i] == '\n'|| str[i] == '\t'))) {
			++k;
			++i;
		}
		if (i - k < my_strlen(str) && j < word_limit) {
			my_strncpy(result[j], &str[i - k], k);
		}
		++j;
	}

	result[j] = NULL;
	return result;
}
