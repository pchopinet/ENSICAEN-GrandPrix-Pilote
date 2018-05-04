//
// Created by pierre on 27/04/18.
//

#include "../include/controller.h"
#include <math.h>
#include "../lib/CCollections/include/PriorityQueue.h"
#include "../lib/CCollections/include/Stack.h"
#include "../lib/CCollections/include/util.h"

/**
 *
 * @return Arraylist with the position of cars
 */
ArrayList readPosition() {
    ArrayList position = newArrayList(0);

    char c;
    int x = 0, y = 0;
    do {
        fscanf(stdin, "%d %d", &x, &y);
        ArrayListAppend(position, newPoint(x, y));

    } while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n');
    return position;
}


void sendAcceleration(int x, int y) {
    char action[5];
    sprintf(action, "%d %d", x, y);
    fprintf(stdout, "%s\n", action);
    fflush(stdout);
}

ArrayList getPointAccessible(Track t, Point position, Vector speed) {

    //TODO : all the possibilities !

    int x = PointX(position);
    int y = PointY(position);

    ArrayList accessible = newArrayList(sizeof(Point));
    Point p1 = newPoint(x + 1, y);
    Point p2 = newPoint(x - 1, y);
    Point p3 = newPoint(x, y + 1);
    Point p4 = newPoint(x, y - 1);

    if (isAccessible(t, p1))
        ArrayListAppend(accessible, p1);
    if (isAccessible(t, p2))
        ArrayListAppend(accessible, p2);
    if (isAccessible(t, p3))
        ArrayListAppend(accessible, p3);
    if (isAccessible(t, p4))
        ArrayListAppend(accessible, p4);

    return accessible;
}

//Pathfinding(Track t, Point p, Vector speed, unsigned int fuel)

Point Dijkstra(Track t, Point finish, Vector speed, ArrayList carPosition, FILE *log) {
    Point anakin = ArrayListGet(carPosition, 0);
    PriorityQueue q = newPriorityQueue();

    fprintf(log, "Allocation\n");
    fflush(log);

    unsigned int **distance = malloc(sizeof(int *));
    Point **previous = malloc(sizeof(Point *));

    for (int y = 0; y < t->height; y++) {
        //fprintf(log, "\n%d : ", y);
        fflush(log);
        distance[y] = malloc(sizeof(int) * t->width);
        previous[y] = malloc(sizeof(Point));
        for (int x = 0; x < t->width; x++) {
            //fprintf(log, "%d ", x);

            Point p = newPoint(x, y);

            if (!PointEqual(anakin, p)) {
                distance[y][x] = INFINITY;
            } else {
                distance[y][x] = 0;
            }
            previous[y][x] = NULL;
            if (isAccessible(t, p)) {
                unsigned int temp = distance[y][x];
                //PointPrint(p, stdout);
                PriorityQueueAdd(q, p, (int) t);
            } else {
                //free(p);
            }
        }
    }
    fprintf(log, "Recherche chemin\t...");
    fflush(log);

    while (!PriorityQueueIsEmpty(q)) {

        Point p = PriorityQueuePop(q);
        ArrayList neighbor = getPointAccessible(t, p, newVector(1, 1));

        for (unsigned int i = 0; i < ArrayListGetLength(neighbor); i++) {
            Point n = ArrayListGet(neighbor, i);
            unsigned int length = distance[PointY(n)][PointX(n)] + 1;
            if (length < distance[PointY(p)][PointX(p)]) {
                distance[PointY(p)][PointX(p)] = length;
                previous[PointY(p)][PointX(p)] = n;
                PriorityQueueChangePrio(q, p, length);
            }
        }
    }
    fprintf(log, "Trouvé !\n");
    fflush(log);

    Stack stack = newStack();
    Point p = newPoint(PointX(finish), PointY(finish));
    while (previous[PointY(p)][PointX(p)] != NULL) {
        StackAdd(stack, p);
        p = previous[PointY(p)][PointX(p)];
    }
    return p;
}

int deltaFuelAcceleration(Vector acc, Vector velocity, int inSand) {
    int accX = VectorX(acc);
    int accY = VectorY(acc);
    int velX = VectorX(velocity);
    int velY = VectorX(velocity);

    int val = accX * accX + accY * accY;
    val += (int) (sqrt(velX * velX + velY * velY) * 3.0 / 2.0);
    if (inSand)
        val += 1;
    return -val;
}

