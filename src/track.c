
#include <unistd.h>
#include <string.h>
#include "../include/track.h"


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

    fscanf(input, "%d %d %d", &(t->width), &(t->height), &(t->fuel));

    if (t->height == 0 || t->width == 0 || t->fuel == 0) {
        exit(1);
    }

    while (fread(&c, sizeof(char), 1, input) == 1 && c != '\n');

    return 0;
}

int readTrack(Track t, FILE *input) {
    int i, j;
    char c;

    t->track = calloc(sizeof(char *), t->height);

    for (i = 0; i < t->height; i++) {
        j = 0;
        t->track[i] = calloc(sizeof(char), t->width);

        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
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
    int i, j;
    char c;
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Error loading file.\n");
        exit(1);
    }

    fscanf(f, "%d %d %d%c", &(t->width), &(t->height), &(t->fuel), &c);
    t->track = calloc(sizeof(char *), t->height);

    for (i = 0; i < t->height; i++) {
        t->track[i] = calloc(sizeof(char), t->width);
        for (j = 0; j < t->width; j++) {
            fscanf(f, "%c", &c);
            printf("%c ", c);
            t->track[i][j] = c;
        }
        if (!feof(f)) {
            fscanf(f, "%c", &c);
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}

/*
int isInTrack(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    return x < t->width && y < t->height && x >= 0 && y >= 0;
}

int isAccessible(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    if (isInTrack(t, p)) {
        char value = t->track[y][x];
        return value != '.';
    }
    return 0;
}

int isSand(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    return isInTrack(t, p) && t->track[y][x] == '~';
}

int isFinishingLine(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    return isInTrack(t, p) && t->track[y][x] == '=';
}

ArrayList FindFinishingLine(Track t) {
    ArrayList finish = newArrayList(sizeof(Point));

    for (int y = 0; y < t->height; y++) {
        for (int x = 0; x < t->width; x++) {
            if (t->track[y][x] == '=') {
                ArrayListAppend(finish, newPoint(x, y));
            }
        }
    }
    return finish;
}
*/
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

