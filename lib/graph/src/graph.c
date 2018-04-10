#include "../include/graph.h"

int makeGraph(Track t) {
    Ladj L = initLadj(t);
    printLadj(L);
}

