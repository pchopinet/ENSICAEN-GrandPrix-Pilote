//
// Created by pierre on 04/05/18.
//

#include <math.h>
#include <unistd.h>
#include "../include/track.h"
#include "../include/controller.h"

int main() {
    int turn = 1;
    FILE *track = fopen("../track/starter_deux_virages.txt", "r");
    Track t = initTrack(stdin);
    FILE *f = fopen("../anakin.log", "w");
    //f = stdout;
    fprintf(f, "Map : %d %d %d\n", t->width, t->height, t->fuel);
    fflush(f);
    TrackPrint(t, f);

    ArrayList finishingLine = FindFinishingLine(t);
    Point finish1 = ArrayListGet(finishingLine, 0);

    fprintf(f, "Finish -> ");
    PointPrint(finish1, f);
    Driver anakin = newDriver(NULL, newVector(0, 0), t->fuel);

    while (!feof(stdin)) {

        fprintf(f, "===== Turn : %d =====\nreadPosition : \n", turn);
        ArrayList a = readPosition();
        for (unsigned int i = 0; i < ArrayListGetLength(a); i++) {
            PointPrint(ArrayListGet(a, i), f);
        }
        fflush(f);
        DriverSetPosition(anakin, ArrayListGet(a, 0));
        if (isSand(t, DriverGetPosition(anakin))) {
            DriverSetSpeed(anakin, newVector(0, 0));
        }

        DriverPrint(anakin, f);

        fprintf(f, "Done!\nDijkstra ");
        fflush(f);
        Point p = Dijkstra(t, finish1, a, f);
        PointPrint(p, f);
        fflush(f);

        Vector acc = DriverCalculateAcceleration(anakin, p);
        fprintf(f, "acc : %d %d\n", VectorX(acc), VectorY(acc));
        sendAcceleration(VectorX(acc), VectorY(acc));

        turn++;

    }
}