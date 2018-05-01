//
// Created by chopinet on 07/04/18.
//


#include "../include/track.h"
#include "../include/controller.h"

int main() {

    Track t = initTrack();
    FILE *f = fopen("../anakin.log", "w");
    fprintf(f, "Map : %d %d %d\n", t->width, t->height, t->fuel);

    fflush(f);

    while (!feof(stdin)) {
        ArrayList a = readPosition();
        Point p1 = ArrayListGet(a, 0);
        //PointPrint(p1);
        sendAcceleration(1, 0);

    }
}