
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int main() {


    point depart;


    float temps;
    clock_t t0, t;
    t0 = clock();

    //Track T = initTrackFromFile("../track/starter_droit_au_but.txt");
    Track T = initTrackFromFile("../track/f-Zero_Crossroad_Circuit.txt");
    //Track T = initTrackFromFile("../track/starter_serpent.txt");
    //Track T = initTrackFromFile("../track/sand.txt");
    //Track T = initTrackFromFile("../track/test.txt");

    Ladj* L = initLadj(T);

    depart.x=4;
    depart.y=61;
    depart.vx=0;
    depart.vy=0;

    depart = L->start[0];

    loadLadj(L,T,depart);
    calculDistance(L);


    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    //printTag(L);
    //printLadj(L);
    //printTag(L);

    printf("\nnb arc %d - nb node %d\n\n",L->nbArc,L->nbNode);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    point finalPoint = dijkstra(L,T,depart);
    printf("Fuel total : %d\n",*totFuel(L,finalPoint));

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);


    Stack* route = findRoute(L,finalPoint);
    printRoute(T,route);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    printf("Distance min: %d\n", *distance(L,L->start[0]));

    return 0;
}
