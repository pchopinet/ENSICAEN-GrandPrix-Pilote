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
 * @version 0.0.1 / 31-01-2018
 */

/**
 * @file abr.h
 */

#ifndef __TP1_H
#define __TP1_H
#include "../lib/graph/file.h"
typedef int element;

typedef struct nodeABR {
	element val;
	struct nodeABR *left;
  struct nodeABR *right;
} nodeABR;

nodeABR* insere (nodeABR *n, element x);
int parcoursLargeur(nodeABR* A) ;

void affiche_arbre(nodeABR* n, int col);

int leefNumber(nodeABR* A);
int preffix (nodeABR* A);
int suffix (nodeABR* A);
int parcoursLargeur(nodeABR* A);


#endif
