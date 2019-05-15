default: build

setup:
	GOPATH=`pwd` go get github.com/google/uuid
	GOPATH=`pwd` go install github.com/google/uuid

build: a.out

a.out: main.go
	GOPATH=`pwd` go build -o a.out main.go

run:
	./a.out

clean:
	rm a.out 2> /dev/null