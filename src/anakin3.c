#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int main() {
    char c;
    int i, j;
    FILE *info = fopen("anakin.log", "w");

    point start, p1, p2;

    int tx, ty;
    int carburant;
    int nbrBoosts = 5;
    int tour = 0;
    int accX = 1, accY = 0;
    int velX = 0, velY = 0;
    char action[100];

    //------------------------------------------------------------------------------------------------------------------
    Track T = malloc(sizeof(struct track_t));

    Ladj *L;
    point finalPoint;
    Stack* route;

    float temps;
    clock_t t0, t;
    t0 = clock();
    //------------------------------------------------------------------------------------------------------------------

    nbrBoosts = nbrBoosts;
    fscanf(stdin, "%d %d %d", &tx, &ty, &carburant);
    fprintf(info, " === >Carte< === \n");
    fprintf(info, "taille %d x %d\n", tx, ty);
    fprintf(info, "Carburant de départ %d \n\n", carburant);
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');

    //------------------------------------------------------------------------------------------------------------------
    T->height = ty;
    T->width = tx;
    T->fuel = carburant;
    T->track = calloc(sizeof(char *), T->height);
    //------------------------------------------------------------------------------------------------------------------

    for (i = 0; i < ty; i++) {
        //--------------------------------------------------------------------------------------------------------------
        j=0;
        T->track[i] = calloc(sizeof(char), T->width);
        //--------------------------------------------------------------------------------------------------------------
        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            fprintf(info, "%c", c);
            //----------------------------------------------------------------------------------------------------------
            T->track[i][j]=c;
            j++;
            //----------------------------------------------------------------------------------------------------------

        }
        fprintf(info, "\n");
    }

    fflush(info);
    fprintf(info, "\n === Debut Course === \n");

    //-------------------------------------------Premier Tour-----------------------------------------------------------
    tour++;
    fprintf(info, "\n === Tour %d === \n", tour);


    fread(&c, sizeof(char), 1, stdin);
    fprintf(info, "%c", c);
    start.y = atoi(&c);

    fread(&c, sizeof(char), 1, stdin);
    fprintf(info, "%c", c);

    fread(&c, sizeof(char), 1, stdin);
    fprintf(info, "%c", c);
    start.x = atoi(&c);

    start.vx = 0;
    start.vy = 0;

    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
        fprintf(info, "%c", c);
    }


    L = initLadj(T);
    loadLadj(L, T, start);
    calculDistance(L);
    finalPoint = dijkstra(L,T,start);
    route = findRoute(L,finalPoint);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    fprintf(info, "\ntemps = %f\n", temps);
    fflush(stdout);
    fflush(info);

    fprintf(info, "\n === Action === \n");

    p1 = pushStack(route);
    p2 = pushStack(route);
    accY = p2.vx-p1.vx;
    accX = p2.vy-p1.vy;
    velY = p1.vx;
    velX = p1.vy;


    fprintf(info, "p1: %d %d %d %d\np2: %d %d %d %d\n",p1.x, p1.y, p1.vx, p1.vy, p2.x, p2.y, p2.vx, p2.vy);

    carburant += deltaCarburantAcceleration(accX, accY, velX, velY, 0);



    sprintf(action, "%d %d", accX, accY);
    fprintf(stdout, "%s\n", action);
    fprintf(info, "%s (carburant restant %d)\n", action, carburant);
    fflush(stdout);
    fflush(info);
    //------------------------------------------------------------------------------------------------------------------

    while (!feof(stdin)) {

        tour++;
        fprintf(info, "\n === Tour %d === \n", tour);
        /* Lecture des positions */

        while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
            fprintf(info, "%c", c);
        }
        fprintf(info, "\n === Action === \n");

        p1 = p2;
        p2 = pushStack(route);
        accY = p2.vx-p1.vx;
        accX = p2.vy-p1.vy;
        velY = p1.vx;
        velX = p1.vy;

        /* Manque la prise en compte du sable (pas de mémorisation de la carte) */
        carburant += deltaCarburantAcceleration(accX, accY, velX, velY, 0);


        /* Écriture de l'accélération. */
        sprintf(action, "%d %d", accX, accY);
        fprintf(stdout, "%s\n", action);
        fprintf(info, "%s (carburant restant %d)\n", action, carburant);
        fflush(stdout); /* Vidage du buffer nécessaire. */
        fflush(info);
    }

    return EXIT_SUCCESS;
}