all: a.out

build: a.out

a.out: main.o
	g++ -o a.out main.o

compile: main.o

# Clubbing MyStack.cpp here since I don't want to create MyStack.h to separate class declaration from implementation.
# Having proper separation makes it cumbersome to copy final code back to leetcode.
main.o: main.cpp MyStack.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm a.out *.o 2> /dev/null
