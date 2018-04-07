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

#ifndef __FILE_H
#define __FILE_H


typedef int T; //the type used

typedef struct node{
   T val;
   struct node* next;
} Node;

typedef struct queue{
   Node* first;
   Node* last;
} Queue;

Node* createNode(T value, Node* next);
Queue createQueue();
void put(T value, Queue*);
void printQueue(Queue);
T push(Queue*);
void concat(Queue*, Queue*);
Queue copyQueue(Queue);
int isEmpty(Queue);

#endif
