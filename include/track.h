/* -*- c-basic-offset: 3 -*-
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Clément Labonne <clement.labonne@ecole.ensicaen.fr>
 * @author Pierre Chopinet <pierre.chopinet@ecole.ensicaen.fr>
 * @version 1.0.0 / 21-05-2018
 */

/**
 * @file track.h
 */

#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "point.h"


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

#endif