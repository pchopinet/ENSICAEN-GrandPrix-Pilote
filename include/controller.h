//
// Created by pierre on 27/04/18.
//

#include "vector.h"
#include "point.h"
#include "../lib/CCollections/include/ArrayList.h"
#include "track.h"

#ifndef ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H
#define ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H


void sendAcceleration(Vector acceleration);

ArrayList readPosition();

ArrayList getPointAccessible(Track t, Point position, Vector speed);

void Dijkstra(Track t, Point p, Vector speed);


#endif //ENSICAEN_GRANDPRIX_PILOTE_CONTROLLER_H
