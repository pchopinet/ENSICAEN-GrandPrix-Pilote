/* -*- c-basic-offset: 3 -*-
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Clément Labonne <clement.labonne@ecole.ensicaen.fr>
 * @author Pierre Chopinet <pierre.chopinet@ecole.ensicaen.fr>
 * @version 1.0.0 / 21-05-2018
 */

/**
 * @file anakin.c
 */

#include <bits/time.h>
#include <time.h>
#include "track.h"
#include "print.h"
#include "graph.h"

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int sable) {
    int valeur = accX * accX + accY * accY;
    valeur += (int) (sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    valeur += sable;
    return -valeur;
}

void sendAcceleration(int ax, int ay, int fuel, FILE *log) {
    char action[10];
    sprintf(action, "%d %d", ax, ay);
    fprintf(stdout, "%s\n", action);
    fprintf(log, "\t%s (carburant restant %d)\n", action, fuel);
    fflush(stdout);
    fflush(log);
}

int main() {

    int lowerFuel = 0, increaseFuel = 0, tour = 0, crash = 1;
    int sf, ax, ay, fuel, bloque;
    float x0 = 0, x1 = 10, x = 2.5;
    char vb, vc;
    float i1 = 0.97f;
    float i2 = 0.93f;
    point a1, a2, b, c, finalPoint;
    Stack *route = NULL;
    Ladj *L = NULL;

    FILE *log = fopen("anakin.log", "w");
    Track T = initTrack(stdin);
    TrackPrint(T, log);
    fuel = T->fuel;


    fprintf(log, "%f %f", i1, i2);

    do {

        tour++;
        fprintf(log, "\nTour: %d\n", tour);
        sf = fscanf(stdin, "%d %d\t%d %d\t%d %d", &(a1.y), &(a1.x), &(b.y), &(b.x), &(c.y), &(c.x));
        fprintf(log, "\tv1: %d %d\tv2: %d %d\tv3: %d %d\n", a1.y, a1.x, b.y, b.x, c.y, c.x);
        fflush(log);

        if (tour == 1 || a1.x != a2.x || a1.y != a2.y) {
            crash = 1;
            fprintf(log, "\tCRASH\n");
            fflush(log);
        } else {
            a1 = a2;
            a2 = pushStack(route);
            crash = 0;
        }

        bloque = (a2.x == b.x && a2.y == b.y) || (a2.x == c.x && a2.y == c.y);

        if (crash || bloque || lowerFuel || increaseFuel) {

            fprintf(log, "\tNouvelle trajectoire : ");
            if (lowerFuel) {
                x1 = x;
                x = (x0 + x1) / 2;
                fprintf(log, " - lowFuel x = %.2f.\n", x);
            } else if (increaseFuel) {
                x0 = x;
                x = (x0 + x1) / 2;
                fprintf(log, " + incFuel x = %.2f.\n", x);
            } else if (tour > 1) {

                x0 = 0;
                x = (x0 + x1) / 2;
                fprintf(log, " route bloquée.\n");
            }else{
                fprintf(log,"\n");
            }

            fflush(log);

            vb = T->track[b.x][b.y];
            vc = T->track[c.x][c.y];
            T->track[b.x][b.y] = '.';
            T->track[c.x][c.y] = '.';

            if (crash == 1) {
                a1.vx = 0;
                a1.vy = 0;
            }
            if (tour > 1) {
                freeLadj(L, T);
            }
            L = initLadj(T);
            loadLadj(L, T, a1);
            finalPoint = dijkstra(L, T, a1, x);
            route = findRoute(L, finalPoint);

            lowerFuel = ((float) *totFuel(L, finalPoint)) > i1 * ((float) fuel);
            increaseFuel = ((float) *totFuel(L, finalPoint)) < i2 * ((float) fuel);


            a1 = pushStack(route);
            a2 = pushStack(route);

            T->track[b.x][b.y] = vb;
            T->track[c.x][c.y] = vc;
        }

        ay = a2.vx - a1.vx;
        ax = a2.vy - a1.vy;

        fuel += deltaCarburantAcceleration(ax, ay, a1.vx, a1.vy, testPt(T, a1, '~'));
        sendAcceleration(ax, ay, fuel, log);

    } while (!feof(stdin));
    return sf;
}