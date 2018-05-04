//
// Created by pierre on 27/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_POINT_H
#define ENSICAEN_GRANDPRIX_PILOTE_POINT_H

#include <stdio.h>


typedef struct point_t *Point;

Point newPoint(int x, int y);

int PointX(Point this);

int PointY(Point this);

int *PointGetXY(Point this);

void PointPrint(Point this);

int PointEqual(Point this, Point test);

#endif //ENSICAEN_GRANDPRIX_PILOTE_POINT_H
