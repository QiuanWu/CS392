NAME = myselect
SRC = myselect.c
OBJ = $(SRC:.c=.o)
CFLAGS = -I ../../include  -Wall -Werror --pedantic

all: $(OBJ)
	cc -L../../lib $(OBJ) -o $(NAME) $(CFLAGS) -lmy -lncurses

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
