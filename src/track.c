
#include <unistd.h>
#include <string.h>
#include "../include/track.h"
#include "../lib/graph/file.h"
#include "../include/point.h"


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
    fscanf(stdin, "%d %d %d", &(t->width), &(t->height), &(t->fuel));

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

Ladj *initLadj(Track t) {

    int i, j, k ,l;
    Ladj *L = malloc(sizeof(Ladj));

    L->nbNode = t->width * t->height;
    L->nbArc = 0;
    L->width = t->width;
    L->height = t->height;

    for (i = 0; i < t->height; i++) {
        for (j = 0; j < t->width; j++) {

            if (t->track[i][j] == '1') {
                L->start[0].x = i;
                L->start[0].y = j;
            } else if (t->track[i][j] == '2') {
                L->start[1].x = i;
                L->start[1].y = j;
            } else if (t->track[i][j] == '3') {
                L->start[2].x = i;
                L->start[2].y = j;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        L->start[i].vx = 0;
        L->start[i].vy = 0;
    }

    L->next = malloc(t->height*sizeof(Cell****));
    L->prev = malloc(t->height*sizeof(Cell****));
    L->tag = malloc(t->height*sizeof(int***));
    L->distance = malloc(t->height*sizeof(int***));
    for (i=0; i<t->height; i++) {
        L->next[i] = malloc(t->width * sizeof(Cell ***));
        L->prev[i] = malloc(t->width * sizeof(Cell ***));
        L->tag[i] = malloc(t->width * sizeof(int **));
        L->distance[i] = malloc(t->width * sizeof(int **));
        for (j=0; j<t->width; j++) {
            L->next[i][j] = malloc(11*sizeof(Cell**));
            L->prev[i][j] = malloc(11*sizeof(Cell**));
            L->tag[i][j] = malloc(11*sizeof(int*));
            L->distance[i][j] = malloc(11*sizeof(int*));
            for (k=0; k<11; k++) {
                L->next[i][j][k] = calloc(11, sizeof(Cell*));
                L->prev[i][j][k] = calloc(11, sizeof(Cell*));
                L->tag[i][j][k] = calloc(11, sizeof(int));
                L->distance[i][j][k] = malloc(11*sizeof(int));
                for (l=0; l<11; l++) {
                    L->distance[i][j][k][l] = -1;
                }
            }
        }
    }
    return L;
}

int loadLadj(Ladj *L, Track T, point p) {

    int normSpeed2;
    int f=0;
    point t, h;
    Cell* C;
    Queue* Q = createQueue();
    put(p, Q);

    while (!isEmpty(Q)) {

        t=push(Q);
        *tag(L,t)=2;

        //printTag(L);
        //usleep(100000);
        //system("clear");

        //printf("-%d %d %d %d-\n",t.x,t.y,t.vx,t.vy);

        for (h.vx=t.vx-1; h.vx<t.vx+2; h.vx++) {
            for (h.vy=t.vy-1; h.vy<t.vy+2; h.vy++) {

                normSpeed2 = h.vx*h.vx + h.vy*h.vy;

                if (normSpeed2 <= 25) {

                    h.x = t.x + h.vx;
                    h.y = t.y + h.vy;

                    if (pointIn(h, L->height, L->width) && T->track[h.x][h.y] == '#' && *tag(L, h) != 2) {


                        if (*tag(L, h) == 0) {
                            put(h, Q);
                            *tag(L, h) = 1;
                        }

                        C = createCell(h, 1, *next(L, t));
                        *next(L, t) = C;

                        C = createCell(t, 1, *prev(L, h));
                        *prev(L, h) = C;

                    } else if (pointIn(h, L->height, L->width) && T->track[h.x][h.y] == '=') {

                        C = createCell(h, 1, *next(L, t));
                        *next(L, t) = C;

                        C = createCell(t, 1, *prev(L, h));
                        *prev(L, h) = C;
                        L->finish[f]=h;

                        f++;
                    }
                }
            }
        }
    }

    L->nbFinish=f;
    return 0;
}

int calculDistance(Ladj* L){

    Queue* Q = createQueue();
    Cell* C;
    point p, q;
    int i;
    int d=0;

    for (i=0; i<L->nbFinish; i++) {
        put(L->finish[i],Q);
        *distance(L,L->finish[i]) = 0;
    }

    while (!isEmpty(Q)) {
        p = push(Q);
        d = *distance(L,p);
        C = *prev(L,p);
        while (C!=NULL) {
            q = C->head;
            if (*distance(L,q) == -1) {
                *distance(L,q) = d+1;
                put(q,Q);
            }
            C = C->next;

        }
    }
    return 0;
}

Queue* calculRoute(Ladj* L, point p) {

    Queue* Q = createQueue();
    Cell* C;
    int d;

    do {
        put(p,Q);
        d = *distance(L,p);
        C = *next(L,p);
        p = C->head;

        while (*distance(L,p) != d-1) {
            C = C->next;
            p = C->head;
        }
    } while (d!=1);

    put(p,Q);

    return Q;
}

int printTag(Ladj *L) {

    int i, j, k, l;

    printf("%d\n", L->tag[15][31][7][0]);

    for (k = 0; k < 11; k++) {
        for (l = 0; l < 11; l++) {

            printf("\nTag table vx:%d vy:%d \n\n", k - 5, l - 5);

            for (i = 0; i < L->height; i++) {
                for (j = 0; j < L->width; j++) {
                    printf("%d", L->tag[i][j][k][l]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int printDistance(Ladj* L) {

    int i, j, k, l;


    for (k = 0; k < 11; k++) {
        for (l = 0; l < 11; l++) {

            printf("\nDistance vx:%d vy:%d \n\n", k - 5, l - 5);

            for (i = 0; i < L->height; i++) {
                for (j = 0; j < L->width; j++) {
                    printf("%d", L->tag[i][j][k][l]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int printRoute(Track T, Queue* Q) {
    point p;
    int i, j;
    while (!isEmpty(Q)) {
        p = push(Q);
        T->track[p.x][p.y] = '0';
    }

    for (i=0; i<T->height; i++) {
        for (j=0; j<T->width; j++) {
            printf("%c",T->track[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int isInTrack(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    return x < t->width && y < t->height && x > 0 && y > 0;
}

int isAccessible(Track t, Point p) {
    int x = PointX(p);
    int y = PointY(p);
    return isInTrack(t, p) && t->track[y][x] != '.';
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

