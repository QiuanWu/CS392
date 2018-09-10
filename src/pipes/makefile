TARGET = pipes
SRC = pipes.c
OBJ = $(SRC:.c=.o)
CFLAGS += -I../../include -g -std=c99 -Wall -Werror -pedantic
LDFLAGS += -L../../lib
LDLIBS += -lmy

all:$(OBJS)
	gcc pipes.c -o pipes -Wall -Werror --pedantic -I../../include -L../../lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f pipes

re: fclean all
