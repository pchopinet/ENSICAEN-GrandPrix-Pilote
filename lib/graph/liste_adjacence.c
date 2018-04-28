
#include "liste_ajdacence.h"

Cell *createCell(point head, float weight, Cell* next) {
    Cell* C;
    C = (Cell *) malloc(sizeof(Cell));
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
            if (L.next[i][j][0][0]) {
                printf("Successeurs de %d.%d : ", i, j);
                printCell(L.next[i][j][0][0]);
            }
        }
    }
    printf("\n");
}

int* tag(Ladj* L, point p) {
    return &(L->tag[p.x][p.y][p.vx+5][p.vy+5]);
}

int* distance(Ladj* L, point p) {
    return &(L->distance[p.x][p.y][p.vx+5][p.vy+5]);
}

Cell** next(Ladj* L, point p) {
    return &(L->next[p.x][p.y][p.vx+5][p.vy+5]);
}

Cell** prev(Ladj* L, point p) {
    return &(L->prev[p.x][p.y][p.vx+5][p.vy+5]);
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
        C = createCell(head, weight, L.next[tail]);
        L.next[tail] = C;
        L.indegree[head]++;
    }
    fclose(f);
    return L;
}*/