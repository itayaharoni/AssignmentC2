CC=gcc
FLAGS= -Wall -g -fPIC
AR=ar
OBJECTS_LIB= myBank.o 
OBJECTS_MAIN= main.c myBank.h

.PHONY= mains maind mybanks mybankd

all: maind mains
mybanks: $(OBJECTS_LIB)
	$(AR) -rcs myBank.a $(OBJECTS_LIB)
mybankd: $(OBJECTS_LIB)
	$(CC) -shared -o myBank.so $(OBJECTS_LIB)
mains: main.o myBank.a
	$(CC) $(FLAGS) -o mains main.o myBank.a
maind: main.o myBank.so
	$(CC) $(FLAGS) -o maind main.o ./myBank.so
myBank.a: $(OBJECTS_LIB)
	$(AR) -rcs myBank.a $(OBJECTS_LIB) 
myBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o myBank.so $(OBJECTS_LIB) 
main.o: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c 
clean:
	rm -f *.so *.a *.o mains maind
