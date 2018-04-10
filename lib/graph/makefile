CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g
PATHOBJ=./obj/
PATHSRC= ./src/
OBJ=$(addprefix $(PATHOBJ),testGraph.o liste_adjacence.o graph.o trackFromFile.o)
all: main

main: $(OBJ)
	$(CC) $^ -o $@

$(PATHOBJ)%.o: $(PATHSRC)%.c
	$(CC) -c  $^ $(CFLAGS) -o $@

clean:
	rm -rf testGraph
	rm -rf $(PATHOBJ)*.o
