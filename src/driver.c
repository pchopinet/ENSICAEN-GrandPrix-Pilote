//
// Created by chopinet on 10/04/18.
//


#include <stddef.h>
#include <util.h>
#include "../include/driver.h"
#include "../include/point.h"

struct driver_t {
    Point position;
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

Point DriverGetPosition(Driver this) {
    return this->position;
}

void DriverSetPosition(Driver this, Point p) {

    if (this->position != NULL) {
        if (PointY(this->position) || PointX(this->position)) {
            int x = PointX(p) - PointX(this->position);
            int y = PointY(p) - PointY(this->position);
            this->speed = newVector(x, y);
        }
    }
    this->position = p;
}


Driver newDriver(Point p, Vector speed, int fuel) {
    Driver d = malloc(sizeof(struct driver_t));
    d->position = p;
    d->speed = speed;
    d->fuel = fuel;
    return d;
}

Vector DriverCalculateAcceleration(Driver this, Point newPosition) {
    int x = PointX(newPosition) - PointX(this->position);
    int y = PointY(newPosition) - PointY(this->position);
    Vector newSpeed = newVector(x, y);
    Vector acc = VectorDiff(this->speed, newSpeed);
    free(newSpeed);
    return acc;
}

void DriverPrint(Driver this, FILE *output) {
    fprintf(output, "Driver : \n\t Position : %d %d\n\t Velocity : %d %d\n\t Fuel : %d\n",
            PointX(this->position),
            PointY(this->position),
            VectorX(this->speed),
            VectorY(this->speed),
            this->fuel
    );
}

void DriverSetSpeed(Driver this, Vector speed) {
    free(this->speed);
    this->speed = speed;
}

