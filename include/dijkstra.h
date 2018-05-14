#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include "pointClement.h"

typedef struct dnode {
    point point;
    float totWeight;
    struct dnode* next;
} Dnode;

typedef struct list {
    Dnode* first;
} List;

Dnode* createDnode(float tot, point p, Dnode* next);

List* createList();

void putInList(List* L, point p, float tot);

point getMin(List* L);

int removeFromList(point p, List* L);

void changeTotWeight(List* L, point p, float tot);

#endif