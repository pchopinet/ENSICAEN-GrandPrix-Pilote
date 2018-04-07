
#include "../include/liste_ajdacence.h"

Cell *createCell(int head, float weight, Cell* next) {
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
        printf("<%5d - %5.1f>\t", C->head, C->weight);
        C = C->next;
    }
    printf("\n");
}

/* allocation dynamique et initialisation */
Ladj initLadj(int nbNode, int nbArc)
{
    Ladj L;
    L.nbNode = nbNode;
    L.nbArc = nbArc;
    L.tab = (Cell **) calloc(nbNode, sizeof(Cell *));
    L.indegree = calloc(nbNode,sizeof(int));
    L.tag = NULL;
    if (L.tab == NULL) exit(-1);
    return L;
}

void printLadj(Ladj L) {
    int i;
    for (i = 0; i < L.nbNode; i++) {
        if (L.tab[i]) {
            printf("Successeurs de %d : ", i);
            printCell(L.tab[i]);
        }
    }
    printf("\n");
}

Ladj loadGraph(char* fileName) {
    int nbNode, nbArc;
    int i, tail, head;
    float weight;
    Ladj L;
    Cell* C;
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
}