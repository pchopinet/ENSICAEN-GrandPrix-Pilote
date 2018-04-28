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
 * @version 0.0.1 / 24-01-2018
 */

/**
 * @file file.h
 */

#ifndef FILE_H
#define FILE_H

#include "../../include/point.h"

typedef point T; //the type used

typedef struct node{
   T val;
   struct node* next;
} Node;

typedef struct queue{
   Node* first;
   Node* last;
} Queue;

int pointIn(point p,int x,int y);

Node* createNode(T value, Node* next);

Queue* createQueue();

void put(T value, Queue*);

T push(Queue*);

void concat(Queue*, Queue*);

Queue copyQueue(Queue);

int isEmpty(Queue*);

#endif
