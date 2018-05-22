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
 * @file abr.c
 */

#include<stdio.h>
#include<stdlib.h>
#include "abr.h"

nodeABR *insert(nodeABR *n, point p, int x) {
    if (n == NULL) {
        n = (nodeABR *) malloc(sizeof(nodeABR));
        n->weight = x;
        n->point = p;
        n->left = NULL;
        n->right = NULL;
    } else if (x < n->weight) {
        n->left = insert(n->left, p, x);
    } else {
        n->right = insert(n->right, p, x);
    }
    return n;
}

nodeABR *extractMin(nodeABR *p, point *pt) {

    nodeABR *q;
    if (p->left == NULL) {
        q = p;
        *pt = p->point;
        p = p->right;
        free(q);
    } else {
        p->left = extractMin(p->left, pt);
    }
    return p;
}
