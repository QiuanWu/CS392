NAME1 = client
NAME2 = server

SRC1 = client.c
SRC2 = server.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

CFLAGS = -I ../../include -Wall -Werror --pedantic

all: client server
	
client: $(OBJ1)
	cc -L../../lib $(OBJ1) -o $(NAME1) -lmy
	
server: $(OBJ2)
	cc -L../../lib $(OBJ2) -o $(NAME2) -lmy
	
clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(NAME1)
	rm -f $(NAME2)

fclean: clean
	
re: fclean all