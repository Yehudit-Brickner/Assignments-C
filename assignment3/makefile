CC = gcc
FLAGS = -Wall -g


# make all
all: stringProg

stringProg: again.o
	$(CC) $(FLAGS) -o stringProg again.o

# make o
again.o: again.c
	$(CC) $(FLAGS) -c again.c

.phony: clean

clean:
	rm -f *.o *.a *.so stringProg
