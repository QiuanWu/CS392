SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
CFLAGS= -I../../include -Wall -Werror --pedantic -std=c99 
LIBNAME = liblist.a
TESTSRC=../../test/testlist.c
TESTFILE= foo
TESTFLAGS = -o $(TESTFILE) $(CFLAGS) -I../../include -L../../lib -lmy -llist

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