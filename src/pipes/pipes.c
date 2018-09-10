/*******************************************************************************
 * Name        : Pipes
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 03/01/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../../include/my.h"
#include <strings.h>
#include <ctype.h>


int main(int argc, char* argv[]) {

    if(argc < 2) {
        my_str("Error: No argument given\n");
        exit(1);
    }

    char *str = my_vect2str(&argv[1]);
    pid_t pid1;
    pid_t pid2;
    int fd1[2];
    int fd2[2];
    char buff1[1024];
    char buff2[1024];

    if(pipe(fd1) < 0) {

        my_str("Error: Pipe failed \n");
        exit(1);
    }
    if((pid1 = fork()) < 0) {

        my_str("Error: Fork failed \n");
        exit(1);
    }

    // Parent process
    else if(pid1 > 0) {

        close(fd1[0]);
        my_str("Parent: ");
        my_str(str);
        my_char('\n');
		write(fd1[1], str, 1024);
        close(fd1[1]);
        wait(0);
    }

    // Child process
    else {
        
        close(fd1[1]);
        read(fd1[0], buff1, 1024);
        my_str("Child: ");

        // Shift letters in child
        char shiftStr[1024];
        char ch;
        int i;
        for (i = 0; buff1[i] != '\0'; ++i) {
            ch = buff1[i];

            if (isalpha(ch)) {

                if (ch >= 'a' && ch <= 'z') {
			        if (ch == 'z') {
    				    ch = 'a';
			        }
					else {
						ch = ch + 1;
					}
			        shiftStr[i] = ch;
	    	    }

                else if (ch >= 'A' &&ch <= 'Z') {
			        if (ch == 'Z') {
				        ch = 'A';
			        }
					else {
						ch = ch + 1;
					}
			        shiftStr[i] = ch;
		        }
            }
			else
				shiftStr[i] = ch;
        }
        shiftStr[i] = '\0';
        my_str(shiftStr);
        my_char('\n');
        close(fd1[0]);

        // Grandchild process
        if(pipe(fd2) < 0) {

            my_str("Error: Pipe2 error \n");
            exit(1);
        }
        if((pid2 = fork()) < 0) {

            my_str("Error: Fork2 error \n");
            exit(1);
        }
        else if(pid2 > 0) {

            close(fd2[0]);
            write(fd2[1], buff1, 1024);
            wait(0);
            close(fd2[1]);
			//return 0;
        }
        else {

            close(fd2[1]);
            read(fd2[0], buff2, 1024);
            my_str("Grandchild: ");

            // Reverse letters in grandchild
            char revStr[1024];
            int k = 0;
            for (int j = my_strlen(buff2) - 1; j >= 0; j--) {
                revStr[k++] = buff1[j];
            }
            revStr[k] = '\0';
            
            my_str(revStr);
            my_char('\n');
            close(fd2[0]);
			//return 0;
        }
    }

    return 0;

}
