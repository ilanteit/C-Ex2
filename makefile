CC=gcc
AR=ar
FLAGS=-Wall -g
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o

all: libmyBank.a myBanks


myBanks: $(OBJECTS_MAIN) libmyBank.a
		$(CC) $(FLAGS) -o myBanks $(OBJECTS_MAIN) libmyBank.a

libmyBank.a: $(OBJECTS_LIB)
		$(AR) -rcs libmyBank.a $(OBJECTS_LIB)
		

myBank.o: myBank.c myBank.h
		$(CC) $(FLAGS) -c myBank.c

main.o: main.c myBank.h
		$(CC) $(FLAGS) -c main.c



.PHONY: clean

clean:
		rm -f *.o *.a *.so myBanks