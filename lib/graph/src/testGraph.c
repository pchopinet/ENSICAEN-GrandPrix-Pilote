#include "../include/genere_graphe.h"
#include "../include/graph.h"


int main() {
    Track t = initTrackFromFile("track.txt");
    makeGraph(t);
    return 0;
}