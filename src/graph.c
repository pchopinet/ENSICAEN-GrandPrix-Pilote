#include "../include/graph.h"

Ladj* initLadj(Track t) {

    int i, j, k ,l, m;
    Ladj *L = malloc(sizeof(Ladj));

    L->nbNode = t->width*t->height*11*11*5;
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
        L->start[i].boost = 5;
    }

    L->next = malloc(t->height*sizeof(Cell*****));
    L->prev = malloc(t->height*sizeof(Cell*****));
    L->tag = malloc(t->height*sizeof(int****));
    L->distance = malloc(t->height*sizeof(int****));
    for (i=0; i<t->height; i++) {
        L->next[i] = malloc(t->width * sizeof(Cell ****));
        L->prev[i] = malloc(t->width * sizeof(Cell ****));
        L->tag[i] = malloc(t->width * sizeof(int ***));
        L->distance[i] = malloc(t->width * sizeof(int ***));
        for (j=0; j<t->width; j++) {
            L->next[i][j] = malloc(11*sizeof(Cell***));
            L->prev[i][j] = malloc(11*sizeof(Cell***));
            L->tag[i][j] = malloc(11*sizeof(int**));
            L->distance[i][j] = malloc(11*sizeof(int**));
            for (k=0; k<11; k++) {
                L->next[i][j][k] = calloc(11, sizeof(Cell**));
                L->prev[i][j][k] = calloc(11, sizeof(Cell**));
                L->tag[i][j][k] = calloc(11, sizeof(int*));
                L->distance[i][j][k] = malloc(11*sizeof(int*));
                for (l=0; l<11; l++) {
                    L->next[i][j][k][l] = calloc(6, sizeof(Cell*));
                    L->prev[i][j][k][l] = calloc(6, sizeof(Cell*));
                    L->tag[i][j][k][l] = calloc(6, sizeof(int));
                    L->distance[i][j][k][l] = malloc(6*sizeof(int));
                    for (m=0; m<6; m++) {
                        L->distance[i][j][k][l][m] = -1;
                    }
                }
            }
        }
    }
    return L;
}

int loadLadj(Ladj *L, Track T, point p) {

    int normSpeed2, ax, ay, fuel;
    int f=0;
    point t, h;
    Queue* Q = createQueue();
    put(p, Q);

    while (!isEmpty(Q)) {

        t=push(Q);
        *tag(L,t)=2;

        for (ax=-2; ax<3; ax++) {
            for (ay=-2; ay<3; ay++) {

                h.vx = t.vx + ax;
                h.vy = t.vy + ay;
                h.x = t.x + h.vx;
                h.y = t.y + h.vy;
                h.boost = t.boost;
                if ((abs(ax)==2 || abs(ay)==2) && h.boost>0) {
                    h.boost--;
                }
                normSpeed2 = h.vx*h.vx + h.vy*h.vy;
                fuel = ax*ax+ay*ay + (int) (sqrt(normSpeed2)*3/2);
                fuel += testPt(T,t,'~') ? 1 : 0;

                if (pointInTrack(h, L) && normSpeed2<=25 && reachable2(T, t, h) &&
                    (!testPt(T,t,'~') || normSpeed2<=1) && ((abs(ax)<2 || abs(ay)<2) || t.boost>0)) {

                    if ((testPt(T,h,'#') || testPt(T,h,'~')) && *tag(L, h) != 2) {

                        if (*tag(L, h) == 0) {
                            put(h, Q);
                            *tag(L, h) = 1;
                        }
                        newArc(h, t, fuel, ax, ay, L);

                    } else if (testPt(T,h,'=')) {
                        newArc(h, t, fuel, ax, ay, L);
                        L->finish[f]=h;
                        f++;
                    }
                } else {
                    h = t;
                    h.vx = 0;
                    h.vy = 0;
                    if (*tag(L, h) == 0) {
                        put(h, Q);
                        *tag(L, h) = 1;
                    }
                    newArc(h, t, fuel, ax, ay, L);
                }
            }
        }
    }

    L->nbFinish=f;
    if (f==0) {
        printf("Erreur arrivée non atteinte!\n");
        return -1;
    } else {
        return 0;
    }
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
    int d, fuel, fuelTot=0;
    put(p,Q);

    do {

        d = *distance(L,p);
        C = *next(L,p);
        p = C->head;
        fuel = C->fuel;
        while (*distance(L,p) != d-1) {
            C = C->next;
            p = C->head;
            fuel = C->fuel;
        }
        fuelTot += fuel;
        put(p,Q);

    } while (d!=1);


    printf("\nFuel : %d\n\n",fuelTot);

    return Q;
}

