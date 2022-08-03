

CC=gcc
FLAGS= -Wall
AR =ar
LIB_STATIC_REC= basicClassification.o advancedClassificationRecursion.o
LIB_DYNAMIC_REC= basicClassification.o advancedClassificationRecursion.o
LIB_STATIC_LOOP= basicClassification.o advancedClassificationLoop.o
LIB_DYNAMIC_LOOP= basicClassification.o advancedClassificationLoop.o



# make everything
all: libclassrec.so libclassrec.a libclassloops.so libclassloops.a mains maindloop maindrec


# make main.o
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c


# make main with differnt libs
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so



# make libs
loops: libclassloops.a
libclassloops.a:$(LIB_STATIC_LOOP)
	$(AR) -rcs libclassloops.a $(LIB_STATIC_LOOP)

recursives: libclassrec.a
libclassrec.a:$(LIB_STATIC_REC)
	$(AR) -rcs libclassrec.a $(LIB_STATIC_REC)

loopd: libclassloops.so
libclassloops.so: $(LIB_DYNAMIC_LOOP)
	$(CC) -shared -o libclassloops.so $(LIB_DYNAMIC_LOOP)

recursived: libclassrec.so
libclassrec.so:$(LIB_DYNAMIC_REC)
	$(CC) -shared -o libclassrec.so $(LIB_DYNAMIC_REC)



# make o files
basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c


.PHONY: clean

clean:
	rm -f prog1 *.o *.a *.so
