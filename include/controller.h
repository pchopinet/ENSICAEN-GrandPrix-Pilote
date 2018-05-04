//
// Created by pierre on 27/04/18.
//

#include "vector.h"
#include "point.h"
#include "../lib/CCollections/include/ArrayList.h"
#include "track.h"

#ifndef ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H
#define ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H


void sendAcceleration(int x, int y);

ArrayList readPosition();

ArrayList getPointAccessible(Track t, Point position, Vector speed);

Point Dijkstra(Track t, Point finish, Vector speed, ArrayList carPosition, FILE *log);

int deltaFuelAcceleration(Vector acc, Vector velocity, int inSand);


#endif //ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H
