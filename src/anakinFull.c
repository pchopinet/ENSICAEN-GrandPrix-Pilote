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
    fprintf(log, "%s (carburant restant %d)\n", action, fuel);
    fflush(stdout);
    fflush(log);
}

int main() {

    int tour = 0, sf;
    point a1, a2, b, c;
    point finalPoint;
    int ax, ay, vx, vy;
    int fuel = 0;
    Stack *route;
    Ladj *L;
    char vb, vc;

    float x;
    int dist;

    int lowerFuel;

    FILE *log = fopen("anakinFull.log", "w");

    Track T = initTrack(stdin);
    TrackPrint(T, log);

    fuel = T->fuel;

    tour++;
    fprintf(log, "\n === Tour %d === \n", tour);


    sf = fscanf(stdin,"%d %d\t%d %d\t%d %d",&(a1.y),&(a1.x),&(b.y),&(b.x),&(c.y),&(c.x));
    fprintf(log,"%d %d\t%d %d\t%d %d\n",a1.y,a1.x,b.y,b.x,c.y,c.x);
    fflush(log);

    a1.vx=0;
    a1.vy=0;

    x = 10;

    L = initLadj(T);
    loadLadj(L, T, a1);
    calculDistance(L);
    finalPoint = dijkstra(L,T,a1,x);
    route = findRoute(L, finalPoint);
    lowerFuel = ((float)*totFuel(L,finalPoint) < 0.95f * (float)fuel) ? 0 : 1;

    a1 = pushStack(route);
    a2 = pushStack(route);
    ay = a2.vx-a1.vx;
    ax = a2.vy-a1.vy;
    vy = a1.vx;
    vx = a1.vy;

    fuel += deltaCarburantAcceleration(ax, ay, vx, vy, testPt(T,a1,'~'));

    sendAcceleration(ax,ay,fuel,log);

    while (!feof(stdin)) {
        tour++;
        fprintf(log, "\nTour: %d\n", tour);

        sf = fscanf(stdin,"%d %d\t%d %d\t%d %d",&(a1.y),&(a1.x),&(b.y),&(b.x),&(c.y),&(c.x));
        fprintf(log,"%d %d\t%d %d\t%d %d\n",a1.y,a1.x,b.y,b.x,c.y,c.x);
        fflush(log);


        if (a1.x!=a2.x || a1.y!=a2.y) {// Pour repartir en cas de crash

            if (lowerFuel) {
                x = 0.5*x;
                fprintf(log,"lowerFuel x = %.0f\n",x);
                fflush(log);
            }

            vb = T->track[b.x][b.y];
            vc = T->track[c.x][c.y];
            T->track[b.x][b.y] = '.';
            T->track[c.x][c.y] = '.';

            a1.vx=0;
            a1.vy=0;

            L = initLadj(T);
            loadLadj(L, T, a1);
            finalPoint = dijkstra(L,T,a1,x);
            route = findRoute(L, finalPoint);
            lowerFuel = ((float)*totFuel(L,finalPoint) < 0.95f * (float)fuel) ? 0 : 1;

            a1 = pushStack(route);

            //fprintf(log,"--Recalcul de route\n--a1 = %d %d\n",a1.y,a1.x);
            //fflush(log);

            T->track[b.x][b.y] = vb;
            T->track[c.x][c.y] = vc;

        } else {
            a1 = a2;
            dist--;
        }

        a2 = pushStack(route);

        if ((a2.x==b.x && a2.y==b.y) || (a2.x==c.x && a2.y==c.y) || lowerFuel) {// pour ne pas se crash dans une autre voiture

            if (lowerFuel) {
                x = 0.5 * x;
                fprintf(log, "lowerFuel x = %.0f\n", x);
                fflush(log);
            }

            vb = T->track[b.x][b.y];
            vc = T->track[c.x][c.y];
            T->track[b.x][b.y] = '.';
            T->track[c.x][c.y] = '.';

            L = initLadj(T);
            loadLadj(L, T, a1);
            finalPoint = dijkstra(L, T, a1, x);
            route = findRoute(L, finalPoint);
            lowerFuel = ((float)*totFuel(L,finalPoint) < 0.95f * (float)fuel) ? 0 : 1;

            T->track[b.x][b.y] = vb;
            T->track[c.x][c.y] = vc;

            a1 = pushStack(route);
            a2 = pushStack(route);


        }

        ay = a2.vx-a1.vx;
        ax = a2.vy-a1.vy;
        vy = a1.vx;
        vx = a1.vy;

        fuel += deltaCarburantAcceleration(ax, ay, vx, vy, testPt(T,a1,'~'));
        sendAcceleration(ax,ay,fuel,log);
    }
    return sf;
}