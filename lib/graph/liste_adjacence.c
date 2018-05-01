
#include "liste_ajdacence.h"

Cell *createCell(point head, int fuel, int ax, int ay, Cell* next) {
    Cell* C;
    C = (Cell *) malloc(sizeof(Cell));
    C->head = head;
    C->fuel = fuel;
    C->ax = ax;
    C->ay = ay;
    C->next = next;
    return C;
}

Lnode* createLnode() {
    Lnode* node = (Lnode*) malloc(sizeof(Lnode));
    node->next = NULL;
    node->prev = NULL;
    node->distance = -1;
    node->tag = 0;
    return node;
}

int* tag(Ladj* L, point p) {
    return &(L->node[p.x][p.y][p.vx+5][p.vy+5][p.boost]->tag);
}

int* distance(Ladj* L, point p) {
    return &(L->node[p.x][p.y][p.vx+5][p.vy+5][p.boost]->distance);
}

Cell** next(Ladj* L, point p) {
    return &(L->node[p.x][p.y][p.vx+5][p.vy+5][p.boost]->next);
}

Cell** prev(Ladj* L, point p) {
    return &(L->node[p.x][p.y][p.vx+5][p.vy+5][p.boost]->prev);
}

int pointInTrack(point p, Ladj* L) {
    int x = L->height;
    int y = L->width;
    return (p.x>=0 && p.y>=0 && p.x<x && p.y<y);
}

int testPt(Track t, point p, char c) {
    return t->track[p.x][p.y] == c;
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


int newArc(point h, point t, int fuel, int ax, int ay, Ladj* L) {
    Cell* C;
    C = createCell(h, fuel, ax, ay, *next(L, t));
    *next(L, t) = C;
    C = createCell(t, fuel, ax, ay, *prev(L, h));
    *prev(L, h) = C;
    L->nbArc++;
    return 0;
}