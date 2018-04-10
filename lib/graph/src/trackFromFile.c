#include "../../../include/track/trackFromFile.h"

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
    FILE* f = fopen(file);
    fscanf(f, "%d %d %d", &(t->height), &(t->width), &(t->fuel));
    fclose(f);
    if (t->height == 0 || t->width == 0 || t->fuel == 0) {
        return 1;
    }
    return 0;
}

int readTrackFromFile(Track t) {
    int i, j;
    char c;
    t->track = malloc(sizeof(char) * t->height);
    FILE* f = fopen(file);
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
