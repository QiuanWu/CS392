/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"


void my_str(char *str){
    
    int i = 0;
    
    if(str != NULL) {
    	
        while(str[i] != '\0') {

            my_char(str[i]);
            i++;
        }
    }

}
