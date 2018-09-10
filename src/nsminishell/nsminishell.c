/*********************************************************************************
 * Name        : nsminishell
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 05/02/2018
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pwd.h>
#include <curses.h>
#include <string.h>
#include "my.h"

#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_RIGHT 'C'
#define KEY_LEFT 'D'
#define BACKSPACE ' '

int main(int argc, char **argv)
{

	char buff[1024]; 	
	int k;
	signal(SIGINT, SIG_IGN);
	initscr();
	my_char('\n');
	noecho();
	for (int i = 0; i < 1024; i++)
		buff[i] = '\0';

	while (1)
	{
		k = getch();

		if (k == 10)
			break;
		else if (k == KEY_UP)
			clear();
		else if (k == KEY_DOWN)
			k = getch();
		else if (k == KEY_LEFT)
			signal(SIGING, SIG_IGN);
		else if (k == KEY_RIGHT)
			continue;

		my_str("NSMINISHELL: ");
		char currDir[1024];
		getcwd(currDir, sizeof(currDir));
		my_str(currDir);
		my_str(" $: ");

		char **cmd = my_str2vect(buff);
		else if (my_strcmp(cmd[0], "cd") == 0)
		{

			if (chdir(cmd[1]) != 0)
			{
				my_str("Error!\n");
			}
		}
		else if (my_strcmp(cmd[0], "exit") == 0)
		{

			my_str("Goodbye!\n");
			exit(0);
		}
		else
		{

			int pid;
			if ((pid = fork()) == 0)
			{

				signal(SIGINT, SIG_DFL);
				if (execvp(cmd[0], cmd) != 1)
				{

					my_str("Invalid argument!\n");
				}
				exit(0);
			}
			else
			{
				wait(NULL);
			}
		}
	}
	for (int i = 0; i < 1024; i++)
		buff[i] = '\0';
	refresh();
	endwin();
}
