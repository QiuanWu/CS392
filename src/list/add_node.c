/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/list.h"
#include "../../include/my.h"

/*
 Inserts a node at the start of the list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 DOES NOT PARSE
*/
void add_node(struct s_node *node, struct s_node **head) {

    if (head != NULL && node != NULL && node->elem != NULL) {

        if ((*head) == NULL) {
            *head = node;
        }
        else {
            if ((*head)->prev != NULL) {
                (*head)->prev->next = node;
            }
            node->prev = (*head)->prev;
            node->next = *head;
            (*head)->prev = node;
            *head = node;
        }
    }
}
