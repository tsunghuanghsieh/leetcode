all: a.out

build: a.out

a.out: main.o
	g++ -o a.out main.o

compile: main.o

main.o: main.cpp Solution.cpp Solution1.cpp Solution2.cpp
	g++ -std=c++17 -c main.cpp

clean:
	rm a.out *.o 2> /dev/null
