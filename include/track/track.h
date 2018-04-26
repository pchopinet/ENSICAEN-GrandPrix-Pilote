
#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>
#include "../driver/driver.h"

#include "../../lib/graph/liste_ajdacence.h"

typedef struct track_t {
    int height;
    int width;
    int fuel;
    char **track;
    Driver * drivers;
} *Track;

Track initTrack();

int readHeader(Track t);

int readTrack(Track t);

Track initTrackFromFile(char* file);

int readHeaderFromFile(Track t, char* file);

int readTrackFromFile(Track t, char* file);

Ladj initLadj(Track t);

int loadLadj(Ladj l, Track t, Point p);

int printTag(Ladj l);

#endif