/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Frees all the nodes in the list.
 CHALLENGE: Write in two lines (allowed to use other methods in 
 this assignment)
*/
void empty_list(struct s_node** head) {
    
    if (head != NULL) {

    	while ((*head) != NULL) { 
    		remove_node(head);
    	}
    }
}
