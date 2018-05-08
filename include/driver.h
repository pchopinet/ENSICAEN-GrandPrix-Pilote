//
// Created by chopinet on 10/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
#define ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H

#include "vector.h"
#include "point.h"

typedef struct driver_t *Driver;

Driver newDriver(Point p, Vector speed, int fuel);

Vector DriverCalculateAcceleration(Driver this, Point newPosition);

Vector DriverGetSpeed(Driver this);

double DriverGetSpeedNorm(Driver this);

int DriverGetFuel(Driver this);

void DriverSetPosition(Driver this, Point p);

Point DriverGetPosition(Driver this);

void DriverPrint(Driver this, FILE *output);

#endif //ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
