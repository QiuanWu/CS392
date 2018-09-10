/*********************************************************************************
 * Name        : Sockettalk
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 04/04/2018
 * Reference   : http://www.linuxhowtos.org/C_C++/socket.htm
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ********************************************************************************/

#include <netdb.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include "../../include/my.h"

void error(char *m)
{
	my_str(m);
	exit(0);
}

int main(int argc, char **argv)
{
	int buff_size = 1024;
	char *name[65535];
	int sock_fd;
	int counter = 0;
	struct sockaddr_in serv_addr, cli_addr;

	if (argc < 2)
		error("Usage: ./server [port]\n");

	my_str("Starting server...\n");
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("Error: Failed opening socket\n");

	int portno = my_atoi(argv[1]);

	if (portno < 1 || portno > 65535)
		error("Error: Invalid port number\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	for (int i = 0; i < 8; i++)
		serv_addr.sin_zero[i] = 0;

	if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("Error: Failed to bind\n");

	listen(sock_fd, 5);

	my_str("Waiting for connections...\n");
	fd_set readfds;
	fd_set mastersock;
	FD_ZERO(&readfds);
	FD_ZERO(&mastersock);
	FD_SET(sock_fd, &mastersock);
	int maxfd = sock_fd;
	char buffer[buff_size];

	while (1)
	{
		bzero(buffer, buff_size);
		readfds = mastersock;
		select(maxfd + 1, &readfds, NULL, NULL, NULL);
		if (FD_ISSET(sock_fd, &readfds) != 0)
		{
			int len = sizeof(struct sockaddr_in);
			int new_socket = accept(sock_fd, (struct sockaddr *)&cli_addr, (socklen_t *)&(len));
			if (!(new_socket < 0)) {
				my_str("New client ");
				my_int(new_socket);
				my_str(" joined");
				my_str(".\n");

				char *message = "Connected successfully to server.\n";
				send(new_socket, message, my_strlen(message), 0);

				FD_SET(new_socket, &mastersock);
				if (new_socket > maxfd)
					maxfd = new_socket;
			}
		}
		else
		{
			for (int i = 0; i <= maxfd; i++)
			{
				if (counter == 0)
					counter = i;

				if (FD_ISSET(i, &readfds))
				{
					int val = recv(i, buffer, sizeof(buffer), 0);
					if (val != 0)
					{
						int mes_is_valid = 1;
						char *message;
						if (my_strncmp(buffer, "/nick ", 6) == 0)
						{
							if ((my_strcmp(name[i - counter], NULL) == 0))
							{
								message = my_strdup("User ");
								name[i - counter] = my_strnconcat(NULL, &buffer[6], val - 7);
								message = my_strconcat(message, name[i - counter]);
								message = my_strconcat(message, " joins the server.\n");
							}
							else
							{
								message = my_strdup(name[i - counter]);
								message = my_strconcat(message, " changes name to ");
								name[i - counter] = my_strnconcat(NULL, &buffer[6], val - 7);
								message = my_strconcat(message, name[i - counter]);
								message = my_strconcat(message, "\n");
							}
						}
						else if (my_strncmp(buffer, "\n", 1) == 0)
							mes_is_valid = 0;

						else if ((my_strncmp(buffer, "/exit ", 6) == 0) || (buffer[6] == '\0' && (my_strncmp(buffer, "/exit", 5) == 0)))
						{
							message = my_strconcat(name[i - counter], " leaves the server.\n");
							name[i - counter] = my_strdup(NULL);
						}
						else
						{
							message = my_strdup(name[i - counter]);
							if (my_strncmp(buffer, "/me ", 4) == 0)
							{
								message = my_strconcat(message, " ");
								message = my_strnconcat(message, &buffer[4], val - 5);
								message = my_strconcat(message, "\n");
							}
							else if (my_strncmp(buffer, "/", 1) == 0)
								mes_is_valid = 0;
								
							else
							{
								message = my_strconcat(message, ": ");
								message = my_strnconcat(message, buffer, val);
							}
						}
						if (mes_is_valid)
						{
							for (int j = 0; j <= maxfd; j++)
							{
								if (FD_ISSET(j, &mastersock) && j != sock_fd && send(j, message, my_strlen(message), 0) != my_strlen(message))								
									my_str("Error: Cannot send the message");
								
							}
						}
						else
						{
							message = "Invalid message\n";
							send(i, message, my_strlen(message), 0);
						}
					}
					else
					{
						my_str("User ");
						my_int(i);
						my_str(" leaves the server.\n");
						close(i);
						FD_CLR(i, &mastersock);
					}
				}
			}
		}
	}
}