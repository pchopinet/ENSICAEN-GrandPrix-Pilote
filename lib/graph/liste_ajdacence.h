
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

typedef struct lnode {
    Cell* next;
    Cell* prev;
    int distance;
    int tag;
} Lnode;

typedef struct ladj {
    int nbNode, nbArc;
    int height, width;
    Lnode* ***** node; //[x][y][vx][vy][boost]
    point start[3];
    point finish[10000]; // Faire une allocationS dynamique !!
    int nbFinish;
} Ladj;

Lnode* createLnode();


Cell *createCell(point head, int fuel, int ax, int ay, Cell* next);

int* tag(Ladj* L, point p);

int* distance(Ladj* L, point p);

Cell** next(Ladj* L, point p);

Cell** prev(Ladj* L, point p);

int pointInTrack(point p, Ladj* L);

int testPt(Track t, point p, char c);

int reachable1(Track t, point p, point q);

int reachable2(Track t, point p, point q);

int newArc(point h, point t, int fuel, int ax, int ay, Ladj* L);

#endif