//
// Created by pierre on 27/04/18.
//

#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/point.h"

struct point_t {
    int x;
    int y;
};

Point newPoint(int x, int y) {
    Point p = malloc(sizeof(struct point_t));
    p->x = x;
    p->y = y;
    return p;
}

int PointX(Point this) {
    return this->x;
}

int PointY(Point this) {
    return this->y;
}

int *PointGetXY(Point this) {
    int *xy = malloc(sizeof(int) * 2);
    xy[0] = this->x;
    xy[1] = this->y;
    return xy;
}

void PointPrint(Point this) {
    printf("Point p : %d %d\n", this->x, this->y);
}



