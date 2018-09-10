/*******************************************************************************
 * Name        : liblist
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 02/21/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"
#include "../../include/list.h"

/*
 Prints the elem of node as a int
*/
void print_int(struct s_node* node) {

    if (node == NULL || node->elem == NULL) {
        my_str("NULL");
    } 
    else {
        my_int(*((int*)(node->elem)));
    }
}
