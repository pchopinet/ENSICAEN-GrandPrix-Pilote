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
 * @file print.h
 */

#ifndef PRINT_H
#define PRINT_H

#include <stdlib.h>
#include <stdio.h>
#include "track.h"
#include "listeAdjacence.h"

int printTag(Ladj *L);

int printDistance(Ladj* l);

int printRoute(Track T, Stack* S);

#endif