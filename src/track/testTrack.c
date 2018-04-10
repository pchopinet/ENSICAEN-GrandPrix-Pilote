
#include "../../include/track/track.h"


int main() {
    Track t = initTrackFromFile("track.txt");
    Ladj L = initLadj(t);
    printLadj(L);
    return 0;
}
