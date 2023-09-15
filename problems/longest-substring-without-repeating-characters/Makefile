all: build

build: go cpp

go: setup
	GOPATH=`pwd` go build -o a.out main.go

setup:
	GOPATH=`pwd` go get github.com/google/uuid
	GOPATH=`pwd` go install github.com/google/uuid

cpp: a.out

a.out: main.o
	g++ -o a.out main.o

# Clubbing Solution.cpp here since I don't want to create Solution.h to separate class declaration from implementation.
# Having proper separation makes it cumbersome to copy final code back to leetcode.
main.o: main.cpp Solution.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm a.out *.o 2> /dev/null
