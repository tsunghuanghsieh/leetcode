all: a.out

build: a.out

a.out: main.o
	g++ -o a.out main.o

compile: main.o

main.o: main.cpp Solution.cpp Solution2.cpp
	g++ -g -Wall -Wno-unused-result -Werror=main -pipe -D_FORTIFY_SOURCE=2 -fno-delete-null-pointer-checks -std=c++17 -c main.cpp

clean:
	rm a.out *.o 2> /dev/null
