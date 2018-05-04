//
// Created by pierre on 04/05/18.
//


#include "../include/track.h"
#include "../include/controller.h"

int main() {
    FILE *track = fopen("../track/starter_droit_au_but.txt", "r");
    Track t = initTrack(track);
    FILE *f = fopen("../anakin.log", "w");
    f = stdout;
    fprintf(f, "Map : %d %d %d\n", t->width, t->height, t->fuel);
    fflush(f);

    ArrayList finishingLine = FindFinishingLine(t);
    Point finish1 = ArrayListGet(finishingLine, 0);

    while (!feof(stdin)) {
        fprintf(f, "readPosition ");
        fflush(f);
        ArrayList a = readPosition();
        fprintf(f, "Done!\nDijkstra ");
        fflush(f);
        Point p = Dijkstra(t, finish1, NULL, a, f);
        fprintf(f, "Done!\n");
        fflush(f);
        PointPrint(p, f);
        sendAcceleration(PointX(p), PointY(p));

    }
}