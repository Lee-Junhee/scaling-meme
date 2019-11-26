ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: parse.o
	$(CC) -o argparse parse.o

parse.o: parse.c
	$(CC) -c parse.c

run: all
	./argparse

clean:
	touch main.o
	touch a.out
	rm *.o
	rm a.out
