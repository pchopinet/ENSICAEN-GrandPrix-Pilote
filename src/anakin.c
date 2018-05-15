//
// Created by chopinet on 07/04/18.
//

#include <bits/time.h>
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int deltaCarburantAcceleration(int accX, int accY, int velX, int velY, int dansSable) {
    int valeur = accX * accX + accY * accY;
    valeur += (int)(sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (dansSable)
        valeur += 1;
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

    float temps;
    clock_t t0, t;
    t0 = clock();

    int tour = 0;
    char c;
    point a1, a2, b1, b2, c1, c2;
    point finalPoint;
    int ax, ay, vx, vy;
    int fuel = 0;
    Stack *route;
    Ladj *L;

    FILE *log = fopen("anakin.log", "w");

    Track T = initTrack(stdin);
    TrackPrint(T, log);

    fuel = T->fuel;

    tour++;
    fprintf(log, "\n === Tour %d === \n", tour);


    fscanf(stdin,"%d %d\t%d %d\t%d %d",&(a1.y),&(a1.x),&(b1.y),&(b1.x),&(c1.y),&(c1.x));
    fprintf(log,"%d %d\t%d %d\t%d %d\n",a1.y,a1.x,b1.y,b1.x,c1.y,c1.x);
    fflush(log);

    a1.vx=0;
    a1.vy=0;


    L = initLadj(T);
    loadLadj(L, T, a1);
    finalPoint = dijkstra(L,T,a1);
    route = findRoute(L, finalPoint);

    a1 = pushStack(route);
    a2 = pushStack(route);
    ay = a2.vx-a1.vx;
    ax = a2.vy-a1.vy;
    vy = a1.vx;
    vx = a1.vy;

    fuel += deltaCarburantAcceleration(ax, ay, vx, vy, 0);

    sendAcceleration(ax,ay,fuel,log);

    while (!feof(stdin)) {
        tour++;
        fprintf(log, "\nTour: %d\n", tour);

        fscanf(stdin,"%d %d\t%d %d\t%d %d",&(a1.y),&(a1.x),&(b1.y),&(b1.x),&(c1.y),&(c1.x));
        fprintf(log,"%d %d\t%d %d\t%d %d\n",a1.y,a1.x,b1.y,b1.x,c1.y,c1.x);
        fflush(log);

        a1 = a2;
        a2 = pushStack(route);
        ay = a2.vx-a1.vx;
        ax = a2.vy-a1.vy;
        vy = a1.vx;
        vx = a1.vy;

        fuel += deltaCarburantAcceleration(ax, ay, vx, vy, 0);
        sendAcceleration(ax,ay,fuel,log);
    }
    return 0;
}
