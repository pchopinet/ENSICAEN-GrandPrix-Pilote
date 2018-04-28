//
// Created by chopinet on 10/04/18.
//


#include <stddef.h>
#include "../include/driver.h"
#include "../include/point.h"

struct driver_t {
    Point coordinate;
    Vector speed;
    int fuel;
};

Vector DriverGetSpeed(Driver this) {
    return this->speed;
}

double DriverGetSpeedNorm(Driver this) {
    return VectorGetNorm(this->speed);
}

int DriverGetFuel(Driver this) {
    return this->fuel;
}

Point DriverGetCoordinate(Driver this) {
    return this->coordinate;
}
