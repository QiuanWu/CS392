/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Returns the value the length of the list
 Parse Once.
*/
int count_s_nodes(struct s_node* head) {
	
	struct s_node* temp = head;
	int counter = 0;

	if (head == NULL) {
		return 0;
	}

	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}

	return counter;	

}
