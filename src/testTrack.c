
#include "../include/track.h"

int main() {
    //Track t = initTrackFromFile("starter_droit_au_but.txt");
    Track t = initTrackFromFile("f-Zero_Crossroad_Circuit.txt");
    Ladj* L = initLadj(t);
    loadLadj(L,t,L->start[0]);
    printTag(L);
    //printf("%d\t%d\n",L->start->x,L->start->y);
    //printLadj(L);
    //printTag(L);
    return 0;
}