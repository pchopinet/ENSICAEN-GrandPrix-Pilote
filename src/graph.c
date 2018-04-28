#include "../include/graph.h"


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
