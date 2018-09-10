/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Prints all the elems as chars separated by a space
*/
void traverse_char(struct s_node* head) {

    if (head != NULL && head->elem != NULL) {

        struct s_node* temp = head;
        while (temp->next != NULL) {

            print_char(temp);
            my_char(' ');
            temp = temp->next;
        }
        print_char(temp);
    } 
    else {
        my_str("NULL");
    }
}

