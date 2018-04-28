//
// Created by chopinet on 10/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
#define ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H

#include "vector.h"
#include "point.h"

typedef struct driver_t *Driver;

void move(Driver p, Vector acceleration);

Vector DriverGetSpeed(Driver this);

double DriverGetSpeedNorm(Driver this);

int DriverGetFuel(Driver this);

Point DriverGetCoordinate(Driver this);

#endif //ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
