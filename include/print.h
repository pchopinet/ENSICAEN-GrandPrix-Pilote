#ifndef PRINT_H
#define PRINT_H

#include <stdlib.h>
#include <stdio.h>
#include "track.h"
#include "../lib/graph/liste_ajdacence.h"

int printTag(Ladj *L);

int printDistance(Ladj* l);

int printRoute(Track T, Queue* Q);

#endif