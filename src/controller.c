//
// Created by pierre on 27/04/18.
//

#include "../include/controller.h"
#include <math.h>
#include "../lib/CCollections/include/util.h"

/**
 *
 * @return Arraylist with the position of cars
 */
ArrayList readPosition() {
    ArrayList position = newArrayList(3, 1, sizeof(Point));

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

    ArrayList accessible = newArrayList(4, 1, sizeof(Point));
    Point p1 = newPoint(x + 1, y);
    Point p2 = newPoint(x - 1, y);
    Point p3 = newPoint(x, y + 1);
    Point p4 = newPoint(x, y - 1);

    if (isAccessible(t, p1))
        ArrayListAppend(accessible, (T) p1);
    if (isAccessible(t, p2))
        ArrayListAppend(accessible, p2);
    if (isAccessible(t, p3))
        ArrayListAppend(accessible, p3);
    if (isAccessible(t, p4))
        ArrayListAppend(accessible, p4);

    return accessible;
}

//Pathfinding(Track t, Point p, Vector speed, unsigned int fuel)

Point *Dijkstra(Track t, Point p, Vector speed) {

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

