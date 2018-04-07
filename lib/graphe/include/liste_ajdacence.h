
//
// Created by clabonne on 04/04/18.
//

#ifndef UNTITLED1_LADJ_H
#define UNTITLED1_LADJ_H
#include <stdio.h>
#include <stdlib.h>


typedef struct cell {
    int head;
    float weight;
    struct cell *next;
} Cell;

typedef struct ladj {
    int nbNode, nbArc;
    Cell **tab;
    int* indegree;
    int* tag;
} Ladj;

Cell *createCell(int, float, Cell *);
void printCell(Cell *);
Ladj initLadj(int, int);
void printLadj(Ladj);
Ladj loadGraph(char *);
#endif