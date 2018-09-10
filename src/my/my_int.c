/*******************************************************************************
 * Name        : Libmy
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 01/31/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "../../include/my.h"


void my_int(int i) {
    unsigned int m = 1;
    unsigned int n;

    if(i < 0) {
        n = -i;
        my_char('-');
    } else {
        n = i;
    }

    while(m <= n/10) {
        m = m * 10;
    }

    while(m > 0) {
        my_char('0' + (n/m));
        n = n % m;
        m = m/10;
    }
}
