CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g

#-fno-stack-protector
#-fno-stack-protector pour supprimer le stack smashing

PATHOBJ=../obj/
PATHSRC= ./
OBJ=$(addprefix $(PATHOBJ),testTrack.o track.o liste_adjacence.o file.o pointClement.o point.o print.o graph.o)
all: testTrack

testTrack: $(OBJ)
	$(CC) -o $@ $^

$(PATHOBJ)%.o: ../lib/graph/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(PATHOBJ)%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^



clean:
	rm -rf testTrack
	rm -rf $(PATHOBJ)*.o

.PHONY: all clean debug
