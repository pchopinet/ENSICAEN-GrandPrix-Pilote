
#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct track_t {
    int height;
    int width;
    int fuel;
    char **track;
} *Track;

Track initTrack();

int readHeader(Track t);

int readTrack(Track t);

#endif //ALGO_AVANCE_GRAPH_H