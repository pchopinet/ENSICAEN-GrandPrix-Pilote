
//
// Created by clabonne on 04/04/18.
//

#ifndef LADJ_H
#define LADJ_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "../../include/track.h"

typedef struct cell {
    point head;
    char c;
    float fuel;
    int ax;
    int ay;
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

Cell *createCell(point head, int fuel, int ax, int ay, Cell* next);

int* tag(Ladj* L, point p);

int* distance(Ladj* L, point p);

Cell** next(Ladj* L, point p);

Cell** prev(Ladj* L, point p);

int pointInTrack(point p, Ladj* L);

int testPt(Track t, point p, char c);

int reachable1(Track t, point p, point q);

int reachable2(Track t, point p, point q);

#endif