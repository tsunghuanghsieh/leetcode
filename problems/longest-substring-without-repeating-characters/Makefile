default: build

setup:
	GOPATH=`pwd` go get github.com/google/uuid
	GOPATH=`pwd` go install github.com/google/uuid

build: setup
	GOPATH=`pwd` go build -o a.out main.go