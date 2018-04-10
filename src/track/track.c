
#include "../../include/track/track.h"


Track initTrack() {
    Track t = malloc(sizeof(struct track_t));
    if (t == NULL) {
        exit(1);
    }
    readHeader(t);
    readTrack(t);
    return t;
}

int readHeader(Track t) {
    fscanf(stdin, "%d %d %d", &(t->height), &(t->width), &(t->fuel));

    if (t->height == 0 || t->width == 0 || t->fuel == 0) {
        return 1;
    }

    char c;
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');

    return 0;
}

int readTrack(Track t) {
    int i, j;
    char c;

    t->track = malloc(sizeof(char) * t->height);
    for (i = 0; i < t->height; i++) {           /* Lecture de la carte ligne par ligne */
        j = 0;
        t->track[i] = malloc(sizeof(char) * t->width);
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            t->track[i][j] = c;
            j++;
        }
    }
    return 0;
}

Track initTrackFromFile(char* file) {
    Track t = malloc(sizeof(struct track_t));
    if (t == NULL) {
        exit(1);
    }
    readHeaderFromFile(t, file);
    readTrackFromFile(t, file);
    return t;
}

int readHeaderFromFile(Track t, char* file) {
    FILE* f = fopen(file,"r");
    fscanf(f, "%d %d %d", &(t->height), &(t->width), &(t->fuel));
    fclose(f);
    if (t->height == 0 || t->width == 0 || t->fuel == 0) {
        return 1;
    }
    return 0;
}

int readTrackFromFile(Track t, char* file) {
    int i, j;
    char c;
    t->track = malloc(sizeof(char) * t->height);
    FILE* f = fopen(file,"r");
    for (i = 0; i < t->height; i++) {           /* Lecture de la carte ligne par ligne */
        t->track[i] = malloc(sizeof(char)* t->width);
        for (j=0; j<t->width; j++) {
            fscanf(file, "%c", &c);
            t->track[i][j] = c;
        }
        if (!feof(f)) {
            fscanf(file, "%c", &c);
        }
    }
    return 0;
}

Ladj initLadj(Track t)
{
    int i, j;
    int k=0;
    Ladj L;
    L->nbNode=t->width*t->height;
    L.nbArc=0;
    for (i=0; i<t->height; i++) {
        for (j=0; j<t->width; j++) {
            if (t->track[i][j] == '1') {
                L.start[0].x = i;
                L.start[0].y = j;
            } else if (t->track[i][j] == '2') {
                L.start[1].x = i;
                L.start[1].y = j;
            } else if (t->track[i][j] == '3') {
                L.start[2].x = i;
                L.start[2].y = j;
            } else if (t->track[i][j] == '=') {
                L.finish[k].x = i;
                L.finish[k].y = j;
                k++;
            }
        }
    }
    L.tab = (Cell ***) calloc(t->height, sizeof(Cell **));
    for (i=0; i<t->width; i++) {
        L.tab[i] = (Cell **) calloc(t->width, sizeof(Cell *));
    }
    //L.indegree = calloc(L.nbNode,sizeof(int));
    //L.tag = NULL;
    if (L.tab == NULL) { //nécesaire?
        exit(1);
    }
    return L;
}