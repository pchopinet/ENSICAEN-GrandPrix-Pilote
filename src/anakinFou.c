//
// Created by chopinet on 07/04/18.
//

#include <bits/time.h>
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int sable) {
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    valeur += sable;
    return -valeur;
}

void sendAcceleration(int ax, int ay, int fuel, FILE* log) {
    char action[10];
    sprintf(action, "%d %d", ax, ay);
    fprintf(stdout, "%s\n", action);
    fprintf(log, "\t%s (carburant restant %d)\n", action, fuel);
    fflush(stdout);
    fflush(log);
}

int main() {

    int lowerFuel = 0, increaseFuel = 0, tour = 0, crash = 1;
    int sf, ax, ay, fuel;
    float x0 = 0, x1 = 10, x = 5;
    char vb, vc;

    point a1, a2, b, c, finalPoint;
    Stack *route;
    Ladj *L;

    FILE *log = fopen("anakinFou.log", "w");

    Track T = initTrack(stdin);
    TrackPrint(T, log);
    fuel = T->fuel;

    do {

        tour++;
        fprintf(log, "\nTour: %d\n", tour);
        sf = fscanf(stdin,"%d %d\t%d %d\t%d %d",&(a1.y),&(a1.x),&(b.y),&(b.x),&(c.y),&(c.x));
        fprintf(log,"\tv1: %d %d\tv2: %d %d\tv3: %d %d\n",a1.y,a1.x,b.y,b.x,c.y,c.x);
        fflush(log);

        if (tour == 1 || a1.x!=a2.x || a1.y!=a2.y) {
            crash = 1;
            fprintf(log,"\tCRASH\n");
            fflush(log);
        } else {
            a1 = a2;
            a2 = pushStack(route);
            crash = 0;
        }

        if (crash == 1 || (a2.x==b.x && a2.y==b.y) || (a2.x==c.x && a2.y==c.y) || lowerFuel || increaseFuel) {

            fprintf(log,"\tNouvelle trajectoire : ");
            if (lowerFuel) {
                x1 = x;
                x = (x0+x1)/2;
                fprintf(log," - lowFuel x = %.2f.\n", x);
            } else if (increaseFuel) {
                x0 = x;
                x = (x0+x1)/2;
                fprintf(log," + incFuel x = %.2f.\n",x);
            } else {
                x0 = 0;
                x = (x0+x1)/2;
                fprintf(log," route bloquée.\n");
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

            L = initLadj(T);
            loadLadj(L, T, a1);
            finalPoint = dijkstra(L,T,a1,x);
            route = findRoute(L, finalPoint);
            lowerFuel = ((float)*totFuel(L,finalPoint) < 0.95f * (float)fuel) ? 0 : 1;
            increaseFuel = ((float)*totFuel(L,finalPoint) > 0.90f * (float)fuel) ? 0 : 1;

            a1 = pushStack(route);
            a2 = pushStack(route);

            T->track[b.x][b.y] = vb;
            T->track[c.x][c.y] = vc;
        }

        ay = a2.vx-a1.vx;
        ax = a2.vy-a1.vy;

        fuel += deltaCarburantAcceleration(ax, ay, a1.vx, a1.vy, testPt(T,a1,'~'));
        sendAcceleration(ax,ay,fuel,log);

    } while (!feof(stdin));
    return sf;
}