/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Adds a node at index n of a list or at the end of the list if n is 
 too large.
 Parse once
*/
void add_node_at(struct s_node *node, struct s_node **head, int n) {

    if (head != NULL && node != NULL && node->elem != NULL) {

        if (*head != NULL) {

            struct s_node *temp = *head;
            int addEnd = 0;
            
            while (n > 0) {
                if (temp->next == NULL && n > 0) {
                    addEnd = 1;
                    break;
                }
                temp = temp->next;
                --n;
            }
            if (addEnd == 0) {
                add_node(node, head);
            }
            else {
                append(node, head);
            }
        }
        else {
            add_node(node, head);
        }
    }
}
