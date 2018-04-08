
//
// Created by clabonne on 04/04/18.
//

#ifndef UNTITLED1_LADJ_H
#define UNTITLED1_LADJ_H
#include <stdio.h>
#include <stdlib.h>
#include "../../track/include/track.h"

typedef struct point {//A mettre dans un autre .h;
    int x;
    int y;
} Point;

typedef struct cell {
    Point head;
    float weight;
    struct cell *next;
} Cell;

typedef struct ladj {
    int nbNode, nbArc;
    Cell** tab;
    Point start[3];
    Point finish[5];
    //int* indegree;
    //int* tag;
} Ladj;

Cell *createCell(Point head, float weight, Cell* next);
void printCell(Cell* C);
Ladj initLadj(Track t);
void printLadj(Ladj L);
//Ladj loadGraph(char* fileName);
#endif