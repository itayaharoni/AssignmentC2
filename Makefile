CC=gcc
FLAGS= -Wall -g -fPIC
AR=ar
OBJECTS_LIB= myBank.o 
OBJECTS_MAIN= main.c myBank.h

.PHONY= all clean mybankd mybanks

all: maind mains
mybanks: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)
mybankd: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a
maind: main.o libmyBank.so
	$(CC) $(FLAGS) -o maind main.o ./libmyBank.so
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB) 
libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB) 
main.o: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c 
clean:
	rm -f *.so *.a *.o mains maind
