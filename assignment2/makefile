CC = gcc
FLAGS = -Wall
AR = ar


# make all
all: main.o my_lib.a
	$(CC) $(FLAGS) -o connections main.o my_lib.a



# make lib
my_lib.a: my_mat.o 
	$(AR) -rcs my_lib.a my_mat.o 



# make o files
my_mat.o : my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

main.o : main.c my_mat.h
	$(CC) $(FLAGS) -c main.c



.phony: clean

clean:
	rm -f prog1 *.o *.a *.so