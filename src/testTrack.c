
#include "../include/track.h"

int main() {
    //Track t = initTrackFromFile("starter_droit_au_but.txt");
    Track t = initTrackFromFile("f-Zero_Crossroad_Circuit.txt");
    Ladj* L = initLadj(t);
    loadLadj(L,t,L->start[0]);
    //printTag(L);
    //printLadj(L);
    //printTag(L);
    calculDistance(L);
    //printDistance(L);
    Queue* route = calculRoute(L,L->start[0]);
    printRoute(t,route);
    return 0;
}