
#include "liste_ajdacence.h"

Cell *createCell(point head, float weight, Cell* next) {
    Cell* C;
    C = (Cell *) malloc(sizeof(Cell));
    C->head = head;
    C->weight = weight;
    C->next = next;
    return C;
}

void printCell(Cell *C) {
    while (C) {
        printf("<%d.%d - %5.1f>\t", C->head.x, C->head.y, C->weight);
        C = C->next;
    }
    printf("\n");
}

/* allocation dynamique et initialisation */


void printLadj(Ladj L) {
    int i, j;
    for (i = 0; i < L.height; i++) {
        for (j = 0; j < L.width; j++) {
            if (L.next[i][j][0][0]) {
                printf("Successeurs de %d.%d : ", i, j);
                printCell(L.next[i][j][0][0]);
            }
        }
    }
    printf("\n");
}

int* tag(Ladj* L, point p) {
    return &(L->tag[p.x][p.y][p.vx+5][p.vy+5]);
}

int* distance(Ladj* L, point p) {
    return &(L->distance[p.x][p.y][p.vx+5][p.vy+5]);
}

Cell** next(Ladj* L, point p) {
    return &(L->next[p.x][p.y][p.vx+5][p.vy+5]);
}

Cell** prev(Ladj* L, point p) {
    return &(L->prev[p.x][p.y][p.vx+5][p.vy+5]);
}

int pointInTrack(point p, Ladj* L) {
    int x = L->height;
    int y = L->width;
    return (p.x>=0 && p.y>=0 && p.x<x && p.y<y);
}

int reachable1(Track t, point p, point q) { //essayer avec des conditions plus permissives

    int b = 1;
    int i, j, x1, x2, y1, y2;

    if (p.x < q.x) {
        x1 = p.x;
        x2 = q.x;
    } else {
        x1 = q.x;
        x2 = p.x;
    }

    if (p.y < q.y) {
        y1 = p.y;
        y2 = q.y;
    } else {
        y1 = q.y;
        y2 = p.y;
    }

    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            b = b && (t->track[i][j] != '.');
        }
    }

    return b;
}

int reachable2(Track t, point p, point q) {

    int i, x, y, s;
    int b=1;
    int dx = q.x-p.x;
    float dy = q.y-p.y;

    s = dx>0 ? 1 : -1;

    if (dx!=0) {
        for (i=0; abs(i)<=abs(dx); i+=s) { // < ou <=
            x = p.x + i;
            y = p.y + (int) i * dy / dx;
            b = b && (t->track[x][y] != '.');
        }
    } else {
        s = dy>0 ? 1 : -1;
        x = p.x;
        for (i=0; abs(i)<abs(dy); i+=s) {
            y = p.y + i;
            b = b && (t->track[x][y]!='.');
        }
    }
    return b;
}