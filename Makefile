
CC= g++ -std=c++11
CFLAGS += -g -Wall
LDFLAGS +=
EXEC = newton_div.o main.o main clean exe

all: $(EXEC)

.PHONY: all

main: main.o 
	$(CC) $(CFLAGS) $(LDFLAGS) main.o newton_div.o -o $@

main.o: main.cpp newton_div.h
	$(CC) -c main.cpp 

newton_div.o: newton_div.cpp newton_div.h
	$(CC) -c newton_div.cpp

clean:
	del -f *.o

exe:
	./main.exe

.PHONY: clean

