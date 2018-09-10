/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Prints all the elems as strings separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_string(struct s_node *head) {

    if (head != NULL && head->elem != NULL) {

        struct s_node *temp = head;
        while (temp->next != NULL) {

            my_char('(');
            if (temp->prev == NULL) {
                my_str("NULL");
            }
            else {
                print_string(temp->prev);
            }
            my_str(" <- ");
            print_string(temp);
            my_str(" -> ");
            print_string(temp->next);
            my_str("), ");
            temp = temp->next;
        }
        my_char('(');
        if (temp->prev == NULL) {
            my_str("NULL");
        }
        else {
            print_string(temp->prev);
        }
        my_str(" <- ");
        print_string(temp);
        my_str(" -> NULL)");
    }
    else if (head != NULL && head->elem == NULL) {
        my_str("(NULL <- NULL -> NULL)");
    }
    else {
        my_str("NULL");
    }
}
