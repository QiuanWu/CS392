/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"


int my_strindex(char *str, char c) {
    int i = 0;
    
    if(str != NULL) {

        while(str[i] != '\0') {

            if(str[i] == c) {
                return i;
            }
            
            i = i + 1;
        }

    }
    return -1;
}