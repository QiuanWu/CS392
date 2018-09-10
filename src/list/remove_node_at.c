/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Removes the node at index n or the last node.
 Parse once
*/
void* remove_node_at(struct s_node** head, int n) {

    void* temp;
    struct s_node* curr;

    if (head == NULL || (*head) == NULL) {
        return NULL;
    }

    curr = (*head);
    temp = curr->elem;

    if (n <= 0 || (*head)->next == NULL) {
        remove_node(head);
        return temp;
    }
    
    while (curr->next != NULL && n > 0) {
        curr = curr->next;
        n--;
    }
    
    temp = curr->elem;

    if (curr->next == NULL){
        curr->prev->next = NULL;
        free(curr);
        return temp;
    }
    
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);

    return temp;

}
