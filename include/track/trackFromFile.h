
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

Track initTrackFromFile(char* file);

int readHeaderFromFile(Track t, char* file);

int readTrackFromFile(Track t, char* file);

#endif