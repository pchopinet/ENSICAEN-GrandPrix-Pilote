
#include "../include/liste_ajdacence.h"

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
Ladj initLadj(Track t)
{
    int i, j;
    int k=0;
    Ladj L;
    L->nbNode=t->width*t->height;
    L.nbArc=0;
    for (i=0; i<t->height; i++) {
        for (j=0; j<t->width; j++) {
            if (t->track[i][j] == '1') {
                L.start[0].x = i;
                L.start[0].y = j;
            } else if (t->track[i][j] == '2') {
                L.start[1].x = i;
                L.start[1].y = j;
            } else if (t->track[i][j] == '3') {
                L.start[2].x = i;
                L.start[2].y = j;
            } else if (t->track[i][j] == '=') {
                L.finish[k].x = i;
                L.finish[k].y = j;
                k++;
            }
        }
    }
    L.tab = (Cell ***) calloc(t->height, sizeof(Cell **));
    for (i=0; i<t->width; i++) {
        L.tab[i] = (Cell **) calloc(t->width, sizeof(Cell *));
    }
    //L.indegree = calloc(L.nbNode,sizeof(int));
    //L.tag = NULL;
    if (L.tab == NULL) { //nécesaire?
        exit(-1);
    }
    return L;
}

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