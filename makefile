CC=gcc
CFLAGS=-Wall -Wextra -pedantic -O3 -I./include/

PATHOBJ=./obj/
PATHSRC= ./src/
PATHBIN= ./bin/
OBJ=$(addprefix $(PATHOBJ),abr.o track.o stack.o listeAdjacence.o file.o point.o graph.o point.o)

all: anakin

testTrack: $(OBJ) $(PATHOBJ)testTrack.o
	$(CC) -o $(PATHBIN)$@ $^ -lm

anakin: $(OBJ) $(PATHOBJ)anakin.o
	$(CC) -o $(PATHBIN)$@ $^ -lm

$(PATHOBJ)%.o: $(PATHSRC)%.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PATHBIN)anakin $(PATHBIN)test*
	rm -rf $(PATHOBJ)*.o

.PHONY: all clean debug