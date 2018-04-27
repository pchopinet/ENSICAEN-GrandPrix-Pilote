//
// Created by pierre on 27/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_POINT_H
#define ENSICAEN_GRANDPRIX_PILOTE_POINT_H

typedef struct point_t *Point;

Point newPoint(int x, int y);

int PointGetX(Point this);

int PointGetY(Point this);

int* PointGetXY(Point this);

#endif //ENSICAEN_GRANDPRIX_PILOTE_POINT_H
