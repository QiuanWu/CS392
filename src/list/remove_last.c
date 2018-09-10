/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Removes the last node from the list.
 Parse Once.
*/
void *remove_last(struct s_node **node) {

    void *temp;
    struct s_node *current;

    if (node == NULL || (*node) == NULL) {
        return NULL;
    }
    current = *node;
    temp = current->elem;
    if (current->next == NULL) {
        remove_node(node);
        return temp;
    }
    while (current->next != NULL) {
        current = current->next;
    }

    temp = current->elem;
    current->prev->next = NULL;
    free(current->next);
    
    return temp;
}
