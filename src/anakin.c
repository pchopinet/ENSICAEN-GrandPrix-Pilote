//
// Created by chopinet on 07/04/18.
//

#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"
//#include "../include/controller.h"

int main() {
    int i, j, tour;
    char c;
    char action[100];
    point a, b;
    int carburant=0;

    //Track T = initTrack();
    FILE *f = fopen("anakin.log", "w");
    /*fprintf(f, "Map : %d %d %d\n\n", t->width, t->height, t->fuel);

    for (i=0; i<t->height; i++) {
        for (j = 0; j < t->width; j++) {
            fprintf(f,"%c",t->track[i][j]);
        }
        fprintf(f,"\n");
    }
    fflush(f);*/

    //Track t = initTrackFromFile("../track/starter_droit_au_but.txt");
    Track T = initTrackFromFile("../track/f-Zero_Crossroad_Circuit.txt");
    //Track t = initTrackFromFile("../track/sand.txt");
    //Track T = initTrackFromFile("../track/test.txt");

    Ladj* L = initLadj(T);
    loadLadj(L,T,L->start[0]);

    calculDistance(L);
    //printf("\nnb arc %d - nb node %d\n\n",L->nbArc,L->nbNode);


    point finalPoint = dijkstra(L,T,L->start[0]);
    //printf("Fuel total : %d\n",*totFuel(L,finalPoint));



    Queue* route = findRoute(L,finalPoint);
    //printRoute(T,route);

    b = push(route);

    while (!feof(stdin)) {
        tour++;
        fprintf(f, "\nTour: %d\n", tour);
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            fprintf(f, "%c", c);
        }
        fprintf(f, "\n === Action === \n");

        /* Manque la prise en compte du sable (pas de mémorisation de la carte) */
        //carburant += deltaCarburantAcceleration(accX, accY, velX, velY, 0);
        //velX += accX;
        //velY += accY;
        a = b;
        b = push(route);
        /* Écriture de l'accélération. */
        sprintf(action, "%d %d", b.vx-a.vx, b.vy-a.vy);
        fprintf(stdout, "%s\n", action);
        fprintf(f, "%s (carburant restant %d)\n", action, carburant);
        fflush(stdout); /* Vidage du buffer nécessaire. */
        fflush(f);
    }
    /*
    while (!feof(stdin)) {
        ArrayList a = readPosition();
        Point p1 = ArrayListGet(a, 0);
        //PointPrint(p1);
        sendAcceleration(1, 0);
    }*/
    return 0;

}
