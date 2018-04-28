
#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>
#include "driver.h"
#include "../include/point.h"

typedef struct track_t {
    int height;
    int width;
    int fuel;
    char **track;
} *Track;

Track initTrack();

int readHeader(Track t);

int readTrack(Track t);

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


#endif