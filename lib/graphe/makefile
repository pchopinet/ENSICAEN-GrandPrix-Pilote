CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fpic -g
PATHOBJ=./obj/
PATHSRC= ./src/
OBJ=$(addprefix $(PATHOBJ),main.o genere_graphe.o library.o file.o L_ADJ.o library_matrice.o)
all: main

main: $(OBJ)
	$(CC) $^ -o $@

$(PATHOBJ)%.o: $(PATHSRC)%.c
	$(CC) -c  $^ $(CFLAGS) -o $@

clean:
	rm -rf main
	rm -rf $(PATHOBJ)*.o
