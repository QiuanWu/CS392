/*********************************************************************************
 * Name        : Sockettalk
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 04/04/2018
 * Reference   : http://www.linuxhowtos.org/C_C++/socket.htm
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ********************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../../include/my.h"

#define BUFF 1024

void error(char *m)
{
	my_str(m);
	exit(0);
}

int main(int argc, char *argv[])
{
	pid_t childPid;
	int sock, n, status;
	struct sockaddr_in serv_addr;
	struct in_addr **addr_list;
	struct hostent *server;
	char getReply[BUFF];
	char buffer[BUFF];
	char *username;
	char IP[100];
	username = (char *)malloc(25 * sizeof(char));

	if (argc < 3)
		error("Usage: ./client [host] [port]\n");

	my_str("Username: ");
	n = read(0, username, 24);
	username[n] = '\0';

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) 
		error("Error: Failed to create socket");

	server = gethostbyname(argv[1]);
	if (server == NULL)
		error("Error: No such host\n");

	addr_list = (struct in_addr **)server->h_addr_list;
	for (int i = 0; addr_list[i] != NULL; i++)
		my_strcpy(IP, inet_ntoa(*addr_list[i]));

	serv_addr.sin_addr.s_addr = inet_addr(IP);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(my_atoi(argv[2]));

	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	my_strcpy(buffer, my_strconcat("/nick ", username));
	n = send(sock, buffer, n + 6, 0);
	childPid = fork();

	if (childPid >= 0)
	{
		if (childPid > 0)
		{
			while (1)
			{
				for (int i = 0; i < BUFF; i++)
					getReply[i] = '\0';
				n = recv(sock, getReply, sizeof(getReply), 0);
				my_str(getReply);
				if (waitpid(childPid, &status, WNOHANG) != 0)
				{
					close(sock);
					exit(0);
				}
			}
		}
		else
		{
			do
			{
				for (int i = 0; i < BUFF; i++)
					buffer[i] = '\0';
				n = read(0, buffer, 1024);
				buffer[n] = '\0';
				n = send(sock, buffer, n, 0);

			} while (!(buffer[6] == '\0' && (my_strncmp(buffer, "/exit", 5) == 0)) && (my_strncmp(buffer, "/exit ", 6) != 0));
			
		}
	}
}
