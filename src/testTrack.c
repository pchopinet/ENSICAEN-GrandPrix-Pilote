
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int main() {

    float temps;
    clock_t t0, t;
    t0 = clock();

    //Track t = initTrackFromFile("../track/starter_droit_au_but.txt");
    Track T = initTrackFromFile("../track/f-Zero_Crossroad_Circuit.txt");
    //Track t = initTrackFromFile("../track/sand.txt");
    //Track T = initTrackFromFile("../track/test.txt");

    Ladj* L = initLadj(T);
    loadLadj(L,T,L->start[0]);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    //printTag(L);
    //printLadj(L);
    //printTag(L);
    calculDistance(L);
    //printDistance(L);
    printf("\nnb arc %d - nb node %d\n\n",L->nbArc,L->nbNode);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    point finalPoint = dijkstra(L,T,L->start[0]);
    printf("Fuel total : %d\n",*totFuel(L,finalPoint));

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);


    Queue* route = findRoute(L,finalPoint);
    printRoute(T,route);

    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    return 0;
}