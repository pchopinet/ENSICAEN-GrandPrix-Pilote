CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g -O3

#-fno-stack-protector
#-fno-stack-protector pour supprimer le stack smashing

PATHOBJ=../obj/
PATHSRC= ./
PATHDRIVERS= ../etc/GrandPrix2018_3.0.3/drivers/
OBJ=$(addprefix $(PATHOBJ),track.o stack.o liste_adjacence.o file.o point.o print.o graph.o dijkstra.o pointClement.o)
all: testTrack anakin anakinFull anakinFou


testTrack: $(OBJ) $(PATHOBJ)testTrack.o
	$(CC) -o $@ $^ -lm

anakin: $(OBJ) $(PATHOBJ)anakin.o
	$(CC) -o $(PATHDRIVERS)$@ $^ -lm

anakinFou: $(OBJ) $(PATHOBJ)anakinFou.o
	$(CC) -o $(PATHDRIVERS)$@ $^ -lm

anakinFull: $(OBJ) $(PATHOBJ)anakinFull.o
	$(CC) -o $(PATHDRIVERS)$@ $^ -lm

$(PATHOBJ)%.o: ../lib/graph/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(PATHOBJ)%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PATHDRIVERS)anakin $(PATHDRIVERS)anakin3 testTrack
	rm -rf $(PATHOBJ)*.o

.PHONY: all clean debug