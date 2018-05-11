//
// Created by pierre on 27/04/18.
//

#include "../include/controller.h"
#include <math.h>
#include <limits.h>
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
    char action[10];
    sprintf(action, "%d %d", x, y);
    fprintf(stdout, "%s\n", action);
    fflush(stdout);
}

ArrayList getPointAccessible(Track t, Point position, Point position_before, Vector speed) {

    //TODO : all the possibilities !

    int x = PointX(position);
    int y = PointY(position);
    int vx = VectorX(speed);
    int vy = VectorY(speed);

    ArrayList accessible = newArrayList(sizeof(Point));
    Point p0 = newPoint(x + vx, y + vy);
    Point p1 = newPoint(x + vx + 1, y + vy);
    Point p2 = newPoint(x + vx - 1, y + vy);
    Point p3 = newPoint(x + vx, y + vy + 1);
    Point p4 = newPoint(x + vx, y + vy - 1);
    Point p5 = newPoint(x + vx - 1, y + vy - 1);
    Point p6 = newPoint(x + vx + 1, y + vy + 1);
    Point p7 = newPoint(x + vx + 1, y + vy - 1);
    Point p8 = newPoint(x + vx - 1, y + vy + 1);

    if (isSand(t, position)) {

        if (isAccessible(t, p0) && !PointEqual(p0, position))
            ArrayListAppend(accessible, p0);
        if (isAccessible(t, p1) && !PointEqual(p1, position))
            ArrayListAppend(accessible, p1);
        if (isAccessible(t, p2) && !PointEqual(p2, position))
            ArrayListAppend(accessible, p2);
        if (isAccessible(t, p3) && !PointEqual(p3, position))
            ArrayListAppend(accessible, p3);
        if (isAccessible(t, p4) && !PointEqual(p4, position))
            ArrayListAppend(accessible, p4);

    } else if (VectorGetNorm(speed) < 2) {

        if (isAccessible(t, p0) && !PointEqual(p0, position))
            ArrayListAppend(accessible, p0);
        if (isAccessible(t, p1) && !PointEqual(p1, position))
            ArrayListAppend(accessible, p1);
        if (isAccessible(t, p2) && !PointEqual(p2, position))
            ArrayListAppend(accessible, p2);
        if (isAccessible(t, p3) && !PointEqual(p3, position))
            ArrayListAppend(accessible, p3);
        if (isAccessible(t, p4) && !PointEqual(p4, position))
            ArrayListAppend(accessible, p4);
        if (isAccessible(t, p5) && !PointEqual(p5, position))
            ArrayListAppend(accessible, p5);
        if (isAccessible(t, p6) && !PointEqual(p6, position))
            ArrayListAppend(accessible, p6);
        if (isAccessible(t, p7) && !PointEqual(p7, position))
            ArrayListAppend(accessible, p7);
        if (isAccessible(t, p8) && !PointEqual(p8, position))
            ArrayListAppend(accessible, p8);

    } else {
        if (isAccessible(t, p0) && !PointEqual(p0, position) && !PointEqual(p0, position))
            ArrayListAppend(accessible, p0);
        if (isAccessible(t, p5) && !PointEqual(p5, position))
            ArrayListAppend(accessible, p5);
        /*if (isAccessible(t, p7) && !PointEqual(p7, position))
            ArrayListAppend(accessible, p7);
        if (isAccessible(t, p8) && !PointEqual(p8, position))
            ArrayListAppend(accessible, p8);*/
    }


    return accessible;
}

//Pathfinding(Track t, Point p, Vector speed, unsigned int fuel)



Point getFirstPoint(Point finish, Point anakin, FILE *log, Point **previous);

void allocate(Track t, Point anakin, PriorityQueue q, int **distance, Point **previous, int **unqueue);

int testIfPointIsCar(ArrayList cars, Point p) {
    for (unsigned i = 1; i < ArrayListGetLength(cars); i++) {
        if (PointEqual(ArrayListGet(cars, i), p)) {
            return 1;
        }
    }
    return 0;
}

Point Dijkstra(Track t, Point finish, ArrayList carPosition, FILE *log) {
    Point anakin = ArrayListGet(carPosition, 0);
    PriorityQueue q = newPriorityQueue();

    fprintf(log, "Allocation\n");
    fflush(log);

    int **distance = malloc(sizeof(int *) * t->height);
    Point **previous = malloc(sizeof(Point *) * t->height);
    int **unqueue = malloc(sizeof(int *) * t->height);

    allocate(t, anakin, q, distance, previous, unqueue);

    fprintf(log, "Creating connexion\n");
    fflush(log);

    while (!PriorityQueueIsEmpty(q)) {

        Point p = PriorityQueuePop(q);
        Point prev = previous[PointY(p)][PointX(p)];
        if (prev == NULL) {
            prev = newPoint(PointX(p), PointY(p));
        }
        //PointPrint(p, log);

        unqueue[PointY(p)][PointX(p)] = 1;
        Vector velocity = newVector(PointX(p) - PointX(prev), PointY(p) - PointY(prev));

        ArrayList neighbor = getPointAccessible(t, p, prev, newVector(0, 0));

        for (unsigned int i = 0; i < ArrayListGetLength(neighbor); i++) {

            Point n = ArrayListGet(neighbor, i);

            if (!testIfPointIsCar(carPosition, n)) {
                if (unqueue[PointY(n)][PointX(n)] == 0) {
                    int length = distance[PointY(p)][PointX(p)] + 1;
                    if (isSand(t, n)) {
                        length++;
                    }
                    PointPrint(p, log);
                    PointPrint(n, log);
                    fprintf(log, "length : %d %d\n", length, distance[PointY(n)][PointX(n)]);
                    if (length < distance[PointY(n)][PointX(n)]) {
                        distance[PointY(n)][PointX(n)] = length;
                        previous[PointY(n)][PointX(n)] = p;
                        PriorityQueueChangePrioSpecificSearch(q, n, length, (int (*)(T, T)) PointEqual);
                    }
                    //fprintf(log, "length : %d %d\n", length, distance[PointY(n)][PointX(n)]);
                }
            }

        }
        free((velocity));
    }

    fprintf(log, "end !\n");
    fflush(log);

    Point p = getFirstPoint(finish, anakin, log, previous);
    return p;
}

void allocate(Track t, Point anakin, PriorityQueue q, int **distance, Point **previous, int **unqueue) {

    for (int y = 0; y < t->height; y++) {
        distance[y] = malloc(sizeof(int) * t->width);
        previous[y] = malloc(sizeof(Point) * t->width);
        unqueue[y] = calloc((size_t) t->width, sizeof(int));

        for (int x = 0; x < t->width; x++) {

            previous[y][x] = NULL;

            Point p = newPoint(x, y);
            if (!PointEqual(anakin, p)) {
                distance[y][x] = INT_MAX;
            } else {
                distance[y][x] = 0;
            }

            if (isAccessible(t, p)) {
                int temp = distance[y][x];
                PriorityQueueAdd(q, p, temp);
            } else {
                //free(p);
            }
        }
    }

}

Point getFirstPoint(Point finish, Point anakin, FILE *log, Point **previous) {
    Point p = newPoint(PointX(finish), PointY(finish));
    Point prev = previous[PointY(p)][PointX(p)];
    if (prev != NULL) {
        while (!PointEqual(previous[PointY(p)][PointX(p)], anakin)) {
            p = previous[PointY(p)][PointX(p)];
            // PointPrint(p, log);
        }
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

