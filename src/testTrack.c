
#include "../include/track.h"
#include "../include/print.h"
#include "../include/graph.h"

int main() {
    //Track t = initTrackFromFile("../track/starter_droit_au_but.txt");
    Track t = initTrackFromFile("../track/f-Zero_Crossroad_Circuit.txt");
    Ladj* L = initLadj(t);
    loadLadj(L,t,L->start[0]);
    //printTag(L);
    //printLadj(L);
    //printTag(L);
    calculDistance(L);
    //printDistance(L);
    Queue* route = calculRoute(L,L->start[0]);
    printRoute(t,route);
    printf("\nnb arc %d : \n\n",L->nbArc);
    return 0;
}