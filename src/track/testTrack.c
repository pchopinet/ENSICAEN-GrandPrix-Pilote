
#include "../../include/track/track.h"

int main() {
    Track t = initTrackFromFile("f-Zero_Landmine_Circuit.txt");
    Ladj L = initLadj(t);
    loadLadj(L,t,L.start[0]);
    printf("%d\t%d\n",L.start->x,L.start->y);
    printLadj(L);
    printTag(L);
    return 0;
}