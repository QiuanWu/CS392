/*******************************************************************************
 * Name        : Pipes
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 03/01/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
 
 #include "../../include/my.h"

/*Takes a vector (array of string ended by a NULL)
Allocates a new string and copies each string from the array into new string separated by a single space, 
until NULL pointer to string is found. Returns new string
{"hello","world",NULL} -> "hello world";*/

char *my_vect2str(char **x) {
   
    char *retStr = NULL;
    int vSize = 0;       
    int strLen = 0;
    int i;
    int j;
    int m;
    int n = 0;

    if (x) {

        for (strLen = 0, m = 0; x[m]; ++m) {
            vSize++;
            strLen += my_strlen(x[m]) + 1;
        }
        retStr = (char *)malloc(sizeof(char) *(strLen));

        if (strLen == 0) {
            retStr[0] = '\0';
            return retStr;
        }

        for (i = 0; i < vSize; i++) {

            for (j = 0; j < my_strlen(x[i]); j++) {

                retStr[n++] = x[i][j];
            }
            if (i != (vSize - 1)) {

                retStr[n++] = ' ';
            }
        }

        retStr[n] = '\0';
        return retStr;
    }

    else
        return retStr;

}
