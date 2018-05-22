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
 * @file stack.h
 */

#ifndef STACK_H
#define STACK_H

#include "point.h"

typedef point T;

typedef struct snode{
    T val;
    struct snode* next;
} SNode;

typedef struct stack{
    SNode* first;
    SNode* last;
    int size;
} Stack;

SNode* createSNode(T value, SNode* next);

Stack* createStack();


void putStack(T value, Stack*);

T pushStack(Stack*);

int isEmptyStack(Stack*);

#endif
