//
// Created by chopinet on 07/04/18.
//

#include <bits/time.h>
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

void sendAcceleration(int x, int y) {
    char action[10];
    sprintf(action, "%d %d", x, y);
    fprintf(stdout, "%s\n", action);
    fflush(stdout);
}

int main() {

    float temps;
    clock_t t0, t;
    t0 = clock();

    int i, j, tour = 0;
    char c;
    char action[100];
    point a, b;
    int carburant = 0;
    FILE *track = fopen("../track/f-Zero_Crossroad_Circuit.txt", "r");

    if (track == NULL) {
        printf("Error loading file.\n");
        exit(1);
    }

    Track T = initTrack(track);
    FILE *f = fopen("anakin.log", "w");
    f = stdout; //pour debug
    fprintf(f, "Map : %d %d %d\n\n", T->width, T->height, T->fuel);

    TrackPrint(T, f);

    Ladj *L = initLadj(T);
    loadLadj(L, T, L->start[0]);

    t = clock();
    temps = (float) (t - t0) / CLOCKS_PER_SEC;
    fprintf(f, "temps = %f\n", temps);

    calculDistance(L);
    fprintf(f, "\nnb arc %d - nb node %d\n\n", L->nbArc, L->nbNode);

    t = clock();
    temps = (float) (t - t0) / CLOCKS_PER_SEC;
    fprintf(f, "temps = %f\n", temps);

    point finalPoint = dijkstra(L, T, L->start[0]);
    fprintf(f, "Fuel total : %d\n", *totFuel(L, finalPoint));

    t = clock();
    temps = (float) (t - t0) / CLOCKS_PER_SEC;
    fprintf(f, "temps = %f\n", temps);

    Queue *route = findRoute(L, finalPoint);
    //printRoute(T, route);

    t = clock();
    temps = (float) (t - t0) / CLOCKS_PER_SEC;
    fprintf(f, "temps = %f\n", temps);

    b = push(route);


    while (!feof(stdin)) {
        tour++;
        fprintf(f, "\nTour: %d\n", tour);
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            fprintf(f, "%c", c);
        }
        fprintf(f, "\n === Action === \n");

        a = b;
        b = push(route);
        /* Écriture de l'accélération. */
        sprintf(action, "%d %d", b.vx - a.vx, b.vy - a.vy);
        fprintf(stdout, "%s\n", action);
        fprintf(f, "%s (carburant restant %d)\n", action, carburant);
        fflush(stdout); /* Vidage du buffer nécessaire. */
        fflush(f);
    }

    return 0;

}
