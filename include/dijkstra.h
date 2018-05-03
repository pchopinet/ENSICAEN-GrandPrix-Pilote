#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include "pointClement.h"

typedef struct dnode {
    int distance;
    point point;
    struct dnode* next;
} Dnode;

typedef struct list {
    Dnode* first;
} List;

Dnode* createDnode(int d, point p, Dnode* next);

List* createList();

void putInList(List* L, point p, int d);

point getMin(List* L);

int removeFromList(point p, List* L);

void changeDistance(List* L, point p, int d);

#endif