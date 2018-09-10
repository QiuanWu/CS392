/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Prints all the elems as strings separated by a space
*/
void traverse_string(struct s_node* head) {

    if (head != NULL && head->elem != NULL) {

        struct s_node* temp = head;
        while (temp->next != NULL) {

            print_string(temp);
            my_char(' ');
            temp = temp->next;
        }
        print_string(temp);
    } 
    else {
        my_str("NULL");
    }
}
