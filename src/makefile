CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g

#-fno-stack-protector
#-fno-stack-protector pour supprimer le stack smashing

PATHOBJ=../obj/
PATHSRC= ./
OBJ=$(addprefix $(PATHOBJ),testTrack.o track.o liste_adjacence.o file.o point.o print.o)
all: testTrack

testTrack: $(OBJ)
	$(CC) -o $@ $^

$(PATHOBJ)liste_adjacence.o: ../lib/graph/liste_adjacence.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(PATHOBJ)file.o: ../lib/graph/file.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(PATHOBJ)%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^



clean:
	rm -rf testTrack
	rm -rf $(PATHOBJ)*.o

.PHONY: all clean debug
