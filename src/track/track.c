
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
    return 0;
}

int readTrack(Track t) {
    int i, j;
    char c;
    t->track = malloc(sizeof(char) * t->height);
    for (i = 0; i < t->height; i++) {           /* Lecture de la carte ligne par ligne */
        j=0;
        t->track[i] = malloc(sizeof(char)* t->width);
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            t->track[i][j] = c;
            j++;
        }
    }
    return 0;
}
