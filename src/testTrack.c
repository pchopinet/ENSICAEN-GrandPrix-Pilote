
#include <time.h>
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int main() {

    float temps;
    clock_t t1, t2;
    t1 = clock();

    //Track t = initTrackFromFile("../track/starter_droit_au_but.txt");
    //Track t = initTrackFromFile("../track/f-Zero_Crossroad_Circuit.txt");
    Track t = initTrackFromFile("../track/sand.txt");
    Ladj* L = initLadj(t);
    loadLadj(L,t,L->start[0]);
    //printTag(L);
    //printLadj(L);
    //printTag(L);
    calculDistance(L);
    //printDistance(L);
    Queue* route = calculRoute(L,L->start[0]);
    printRoute(t,route);
    printf("\nnb arc %d - nb node %d\n\n",L->nbArc,L->nbNode);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    return 0;
}