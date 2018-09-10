TARGET = nsminishell
SRC = nsminishell.c
OBJ = $(SRC:.c=.o)
CFLAGS += -I../../include -g -std=c99 -Wall -Werror -pedantic
LDFLAGS += -L../../lib
LDLIBS += -lmy

all:$(OBJS)
	gcc nsminishell.c -o nsminishell -Wall -Werror --pedantic -I../../include -L../../lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f nsminishell

re: fclean all
