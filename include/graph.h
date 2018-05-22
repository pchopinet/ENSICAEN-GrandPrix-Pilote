
#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "track.h"
#include "../lib/graph/file.h"
#include "../lib/graph/stack.h"
#include "../lib/graph/abr.h"
#include "../lib/graph/liste_ajdacence.h"


Ladj* initLadj(Track t);

int loadLadj(Ladj *l, Track T, point p);

int calculDistance(Ladj* L);

Stack* findRoute(Ladj* L, point p);

point dijkstra(Ladj* L, Track t, point a, float x);

void freeLadj(Ladj* L, Track T);

#endif