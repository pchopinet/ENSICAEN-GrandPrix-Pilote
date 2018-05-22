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
 * @file track.c
 */

#include <unistd.h>
#include <string.h>
#include "track.h"


Track initTrack(FILE *input) {
    Track t = malloc(sizeof(struct track_t));
    if (t == NULL) {
        exit(1);
    }
    readHeader(t, input);
    readTrack(t, input);
    return t;
}

int readHeader(Track t, FILE *input) {
    char c;
    int sf;

    sf = fscanf(input, "%d %d %d", &(t->width), &(t->height), &(t->fuel));

    if (t->height == 0 || t->width == 0 || t->fuel == 0) {
        exit(1);
    }

    while (fread(&c, sizeof(char), 1, input) == 1 && c != '\n');

    return sf;
}

int readTrack(Track t, FILE *input) {
    int i, j;
    char c;

    t->track = calloc(sizeof(char *), t->height);

    for (i = 0; i < t->height; i++) {
        j = 0;
        t->track[i] = calloc(sizeof(char), t->width);

        while (fread(&c, sizeof(char), 1, input) == 1 && c != '\n') {
            t->track[i][j]=c;
            j++;
        }
    }
    return 0;
}

Track initTrackFromFile(char *file) {
    Track t = malloc(sizeof(struct track_t));
    if (t == NULL) {
        exit(1);
    }
    readTrackFromFile(t, file);
    return t;
}


int readTrackFromFile(Track t, char *file) {
    int i, j, sf;
    char c;
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Error loading file.\n");
        exit(1);
    }

    sf = fscanf(f, "%d %d %d%c", &(t->width), &(t->height), &(t->fuel), &c);
    t->track = calloc(sizeof(char *), t->height);

    for (i = 0; i < t->height; i++) {
        t->track[i] = calloc(sizeof(char), t->width);
        for (j = 0; j < t->width; j++) {
            sf = fscanf(f, "%c", &c);
            printf("%c ", c);
            t->track[i][j] = c;
        }
        if (!feof(f)) {
            sf = fscanf(f, "%c", &c);
        }
        printf("\n");
    }
    fclose(f);
    return sf;
}


void TrackPrint(Track t, FILE *output) {
    fprintf(output, "Map : %d %d %d\n\n", t->width, t->height, t->fuel);
    for (int y = 0; y < t->height; y++) {
        for (int x = 0; x < t->width; x++) {
            fprintf(output, "%c", t->track[y][x]);
        }
        fprintf(output, "\n");
    }
    fflush(output);
}

