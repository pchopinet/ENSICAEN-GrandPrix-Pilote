//
// Created by pierre on 27/04/18.
//

#include "../include/controller.h"
#include <math.h>
#include "../lib/CCollections/include/util.h"

/**
 *
 * @warning NOT TESTED
 * @return Arraylist with the position of cars
 */
ArrayList readPosition() {
    ArrayList position = newArrayList(3, 1, sizeof(struct point_t));

    char c;
    int x = 0, y = 0, i = 0;
    while (fread(&c, sizeof(char), 1, stdin) == 1 && c != '\n') {
        if (c < '9' && c > '0') {
            if (i % 2 == 0) {
                x = c - '0';
            } else {
                y = c - '0';
                ArrayListAppend(position, newPoint(x, y));
            }
            i++;
        }
    }
    return position;

}

void sendAcceleration(int x, int y) {
    char action[5];
    sprintf(action, "%d %d", x, y);
    fprintf(stdout, "%s\n", action);
}

ArrayList getPointAccessible(Track t, Point position, Vector speed) {

    //TODO : all the possibilities !

    int x = PointX(position);
    int y = PointY(position);

    ArrayList accessible = newArrayList(4, 1, sizeof(struct point_t));
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

