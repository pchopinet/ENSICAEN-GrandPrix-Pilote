/* -*- c-basic-offset: 3 -*-
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Clément Labonne <clement.labonne@ecole.ensicaen.fr>
 * @author Pierre Chopinet <pierre.chopinet@ecole.ensicaen.fr>
 * @version 1.0.0 / 21-05-2018
 */

/**
 * @file abr.h
 */

#ifndef __TP1_H
#define __TP1_H

#include "point.h"

typedef struct nodeABR {
	int weight;
	point point;
	struct nodeABR *left;
	struct nodeABR *right;
} nodeABR;

nodeABR* insert(nodeABR *n, point p, int x);

nodeABR* extractMin(nodeABR* p, point* pt);


#endif
