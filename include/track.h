
#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ArrayList.h>
#include "driver.h"
#include "../include/point.h"
//#include "../lib/CCollections/include/ArrayList.h"

typedef struct track_t {
    int height;
    int width;
    int fuel;
    char **track;
} *Track;

Track initTrack(FILE *input);

int readHeader(Track t, FILE *input);

int readTrack(Track t, FILE *input);

void TrackPrint(Track t, FILE *output);

Track initTrackFromFile(char *file);

int readHeaderFromFile(Track t, char *file);

int readTrackFromFile(Track t, char *file);

/**
 * @warning this function doesn't test if there is a car !
 *
 * @param t
 * @param p
 * @return
 */


int isAccessible(Track t, Point p);

int isSand(Track t, Point p);

int isFinishingLine(Track t, Point p);

ArrayList FindFinishingLine(Track t);

#endif