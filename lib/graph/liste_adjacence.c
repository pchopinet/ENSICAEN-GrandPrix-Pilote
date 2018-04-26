
#include "liste_ajdacence.h"

Cell *createCell(Point head, float weight, Cell* next) {
    Cell* C;
    C = (Cell *) malloc(sizeof(Cell));
    if (C == NULL) exit(-1);
    C->head = head;
    C->weight = weight;
    C->next = next;
    return C;
}

void printCell(Cell *C) {
    while (C) {
        printf("<%d.%d - %5.1f>\t", C->head.x, C->head.y, C->weight);
        C = C->next;
    }
    printf("\n");
}

/* allocation dynamique et initialisation */


void printLadj(Ladj L) {
    int i, j;
    for (i = 0; i < L.height; i++) {
        for (j = 0; j < L.width; j++) {
            if (L.tab[i][j]) {
                printf("Successeurs de %d.%d : ", i, j);
                printCell(L.tab[i][j]);
            }
        }
    }
    printf("\n");
}

/*
Ladj loadGraph(char* fileName) {
    int nbNode, nbArc;
    int i, tail, head;
    float weight;
    Ladj L;
    Cell *C;
    FILE *f;

    f = fopen(fileName, "rt");
    if (f == NULL) {
        exit(-1);
    }
    fscanf(f, "%d %d", &nbNode, &nbArc);
    L = initLadj(nbNode, nbArc);
    for (i = 0; i < nbArc; i++) {
        fscanf(f, "%d %d %f", &tail, &head, &weight);
        C = createCell(head, weight, L.tab[tail]);
        L.tab[tail] = C;
        L.indegree[head]++;
    }
    fclose(f);
    return L;
}*/