/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Adds a node to the end of a list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 Parse once
*/
void append(struct s_node *node, struct s_node **head) {

	if (head != NULL && node != NULL && node->elem != NULL) {

		if (*head != NULL) {

			struct s_node *temp = *head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = node;
			node->prev = temp;
			node->next = NULL;
		}
		else {
			*head = node;
		}
	}
}
