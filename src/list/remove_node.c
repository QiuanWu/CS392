/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/* 
 Removes the given node from the list. Returns elem and frees the 
 node from memory.
 DOES NOT PARSE.
*/
void *remove_node(struct s_node **node) {

    void *data = NULL;
    if (node != NULL && *node != NULL) {

        struct s_node *temp = *node;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        *node = temp->next;
        data = temp->elem;
        free(temp);
    }
    
    return data;
}
