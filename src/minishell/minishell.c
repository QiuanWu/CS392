/*******************************************************************************
 * Name        : Minishell
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 03/07/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"


int main() {

    char buff[1024];
    int r;
    signal(SIGINT, SIG_IGN);
    for(int i = 0; i < 1024; i++)
		buff[i]='\0';

    while (1) {

        my_str("MINISHELL: ");
        char currDir[1024];
        getcwd(currDir, sizeof(currDir));
        my_str(currDir); 
        my_str(" $: ");

        r = read(0, &buff, 1024);

        if (r > 1) {
            char **cmd = my_str2vect(buff);
            if (my_strcmp(cmd[0], "help") == 0)  {

                my_str("Minishell basic commands:\n");
                my_str(" help: Get some help with what commands to use");
                my_str(" cd : Change the current directory into another one\n");
                my_str(" exit : Exit the minishell\n");
            }
            else if (my_strcmp(cmd[0], "cd") == 0) {

                if (chdir(cmd[1]) != 0) {
                    my_str("There is an error!\n");
                }
            }
            else if (my_strcmp(cmd[0], "exit") == 0) {

                my_str("Goodbye!\n");
                exit(0);
            }
            else {

                int pid;
                if ((pid = fork()) == 0)  {

                    signal(SIGINT, SIG_DFL);
                    if (execvp(cmd[0], cmd) != 1) {

                        my_str("Invalid argument!\n");
                        my_str("Minishell basic commands:\n");
                        my_str(" cd\n");
                        my_str(" help\n");
                        my_str(" exit\n");
                    }
                    exit(0);
                }
                else {
                    wait(NULL);
                }
            }
        }
        for (int i = 0; i < 1024; i++)
        buff[i] = '\0';
    }
}
