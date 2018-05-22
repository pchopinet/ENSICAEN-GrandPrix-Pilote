
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int main() {


    point depart;


    float temps,x;
    clock_t t0, t;
    t0 = clock();

    Track T = initTrackFromFile("../tracks/starter_droit_au_but.txt");
    //Track T = initTrackFromFile("../tracks/f-Zero_Crossroad_Circuit.txt");
    //Track T = initTrackFromFile("../tracks/starter_serpent.txt");
    //Track T = initTrackFromFile("../tracks/sand.txt");
    //Track T = initTrackFromFile("../tracks/test.txt");

    Ladj* L = initLadj(T);

    depart.x=4;
    depart.y=61;
    depart.vx=0;
    depart.vy=0;

    depart = L->start[0];

    loadLadj(L,T,depart);
    calculDistance(L);
    x = T->fuel/(*distance(L,depart));
    point finalPoint = dijkstra(L,T,depart,x);
    Stack* route = findRoute(L,finalPoint);

    printf("\nnb arc %d - nb node %d\n\n",L->nbArc,L->nbNode);
    printf("Fuel total : %d\n",*totFuel(L,finalPoint));
    printf("Distance min: %d\n", *distance(L,L->start[0]));
    printRoute(T,route);
    t = clock();
    temps = (float)(t-t0)/CLOCKS_PER_SEC;
    printf("temps free 1 = %f\n", temps);


    return 0;
}
