CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g
PATHOBJ=../../obj/track/
PATHSRC= ./
OBJ=$(addprefix $(PATHOBJ),track.o testTrack.o )
all: main

main: $(OBJ)
	$(CC) $^ -o $@

$(PATHOBJ)%.o: $(PATHSRC)%.c
	$(CC) -c  $^ $(CFLAGS) -o $@
$(PATHOBJ)%.o: ../../lib/graph/src/liste_adjacence.c
	$(CC) -c  $^ $(CFLAGS) -o $@

clean:
	rm -rf main
	rm -rf $(PATHOBJ)*.o
