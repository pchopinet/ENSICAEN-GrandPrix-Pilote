
//
// Created by clabonne on 04/04/18.
//

#ifndef LADJ_H
#define LADJ_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"


typedef struct cell {
    Point head;
    char c;
    float weight;
    struct cell *next;
} Cell;

typedef struct ladj {
    int nbNode, nbArc;
    int height, width;
    Cell***** tab; //[x][y][vx][vy]
    Point start[3];
    Point finish[14]; // Faire une allocationS dynamique !!
    int**** tag;
} Ladj;

Cell *createCell(Point head, float weight, Cell* next);
void printCell(Cell* C);
void printLadj(Ladj L);
//Ladj loadGraph(char* fileName);
#endif