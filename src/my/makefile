SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 
LIBNAME = libmy.a
TESTSRC=../../test/testmy2.c
TESTFILE= foo
TESTFLAGS = -o $(TESTFILE) $(CFLAGS) -L../../lib -lmy

all: $(OBJS)
	ar -rc $(LIBNAME) $(OBJS)
	ranlib $(LIBNAME) 
	mv $(LIBNAME) ../../lib

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ../../lib/$(LIBNAME)

re: fclean all

test: 
	gcc $(TESTSRC) $(TESTFLAGS)

ret: re test