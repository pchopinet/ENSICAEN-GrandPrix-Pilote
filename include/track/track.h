
#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>

#include "../../lib/graph/include/liste_ajdacence.h"

typedef struct track_t {
    int height;
    int width;
    int fuel;
    char **track;
} *Track;

Track initTrack();

int readHeader(Track t);

int readTrack(Track t);

Track initTrackFromFile(char* file);

int readHeaderFromFile(Track t, char* file);

int readTrackFromFile(Track t, char* file);

Ladj initLadj(Track t);

#endif //ALGO_AVANCE_GRAPH_H