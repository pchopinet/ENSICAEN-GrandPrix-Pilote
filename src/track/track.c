
#include <unistd.h>
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
    readTrackFromFile(t, file);
    return t;
}



int readTrackFromFile(Track t, char* file) {
    int i, j;
    char c;
    FILE* f = fopen(file,"r");
    if(f == NULL) {
        printf("Error loading file.\n");
        exit(1);
    }

    fscanf(f, "%d %d %d%c", &(t->width), &(t->height), &(t->fuel),&c);
    t->track = calloc(sizeof(char*), t->height);

    for (i = 0; i < t->height; i++) {
        t->track[i] = calloc(sizeof(char), t->width);
        for (j=0; j<t->width; j++) {
            fscanf(f, "%c", &c);
            printf("%c ",c);
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

Ladj initLadj(Track t) {

    int i, j;
    int k=0;
    Ladj L;

    L.nbNode=t->width*t->height;
    L.nbArc=0;
    L.width=t->width;
    L.height=t->height;

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
    L.tag = calloc(t->height,sizeof(int*));
    for (i=0; i<t->height; i++) {
        L.tab[i] = (Cell **) calloc(t->width, sizeof(Cell *));
        L.tag[i] = calloc(t->width, sizeof(int));
    }

    if (L.tab == NULL || L.tag == NULL) exit(-1);
    return L;
}

int loadLadj(Ladj L, Track T, Point p) {

    Point t, h;
    Cell* C;
    Queue Q = createQueue();
    put(p, &Q);

    while (!isEmpty(Q)) {

        t=push(&Q);
        L.tag[t.x][t.y]=2;

        //printTag(L);
        //usleep(100000);
        //system("clear");

        for (h.x=t.x-1; h.x<t.x+2; h.x++) {
            for (h.y=t.y-1; h.y<t.y+2; h.y++) {

                if (pointIn(h,L.height,L.width) && T->track[h.x][h.y]=='#' && L.tag[h.x][h.y]!=2) {

                    if (L.tag[h.x][h.y]==0) {
                        put(h,&Q);
                        L.tag[h.x][h.y]=1;
                    }

                    C = createCell(h,1,L.tab[t.x][t.y]);
                    L.tab[t.x][t.y]=C;

                } else if (pointIn(h,L.height,L.width) && T->track[h.x][h.y]=='=') {

                    C = createCell(h,1,L.tab[t.x][t.y]);
                    L.tab[t.x][t.y]=C;
                }
            }
        }
    }
    return 0;
}

int printTag(Ladj l) {

    int i, j;
    printf("\nTag table : \n\n");

    for (i=0; i<l.height; i++) {
        for (j=0; j<l.width; ++j) {
            printf("%d",l.tag[i][j]);
        }
        printf("\n");
    }
    return 0;
}