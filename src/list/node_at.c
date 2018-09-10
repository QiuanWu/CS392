/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Returns a pointer to the node at index n or the last node.
 Parse once
*/
struct s_node* node_at(struct s_node* head, int n) {
	
	if (head != NULL) {

    	while (n > 0 && head-> next != NULL) {
			
    		head = head->next;
    		n--;
    	}
	    return head;

    }
    return NULL;

}
