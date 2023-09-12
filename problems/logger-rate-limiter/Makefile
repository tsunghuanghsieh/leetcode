all: a.out

build: a.out

a.out: main.o
	g++ -o a.out main.o

compile: main.o

main.o: main.cpp Logger.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm a.out *.o 2> /dev/null
