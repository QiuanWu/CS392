/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/list.h"
#include "../../include/my.h"

/*
 Allocates and returns a new node with the given pointers. You may
 create nodes with NULLs.
*/
struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous) {
	
	struct s_node* new_node = (struct s_node*)malloc(sizeof(struct s_node));
	new_node->elem = elem;
	new_node->next = next;
	new_node->prev = previous;
	
	return new_node;
}
