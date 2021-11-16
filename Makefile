CC=gcc
FLAGS=
SRC=containers/bucket/bucket.c containers/linked_list/linked_list.c containers/iterator/iterator.c main.c

all: compile run

compile: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o main

run: main
	./main