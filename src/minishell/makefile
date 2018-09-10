TARGET = minishell
SRC = minishell.c
OBJ = $(SRC:.c=.o)
CFLAGS += -I../../include -g -std=c99 -Wall -Werror -pedantic
LDFLAGS += -L../../lib
LDLIBS += -lmy

all:$(OBJS)
	gcc minishell.c -o minishell -Wall -Werror --pedantic -I../../include -L../../lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f minishell

re: fclean all
