
//
// Created by clabonne on 04/04/18.
//

#ifndef LADJ_H
#define LADJ_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"


typedef struct cell {
    point head;
    char c;
    float weight;
    struct cell *next;
} Cell;

typedef struct ladj {
    int nbNode, nbArc;
    int height, width;
    Cell***** next; //[x][y][vx][vy]
    Cell***** prev;
    int**** tag;
    int**** distance;
    point start[3];
    point finish[1210]; // Faire une allocationS dynamique !!
    int nbFinish;
} Ladj;

Cell *createCell(point head, float weight, Cell* next);

int* tag(Ladj* L, point p);

int* distance(Ladj* L, point p);

Cell** next(Ladj* L, point p);

Cell** prev(Ladj* L, point p);

//void printCell(Cell* C);
//void printLadj(Ladj L);
//Ladj loadGraph(char* fileName);
#endif