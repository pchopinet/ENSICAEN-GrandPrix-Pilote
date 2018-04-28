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
 * @file file.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"file.h"

int pointIn(point p,int x,int y) {
    return (p.x>=0 && p.y>=0 && p.x<x && p.y<y);
}

Node* createNode(T value, Node* next) {
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=value;
    n->next=next;
    return n;
}

Queue* createQueue() {
    Queue* Q = malloc(sizeof(Queue));
    Q->last=NULL;
    Q->first=NULL;
    return Q;
}

int isEmpty(Queue* Q) {
    return Q->last==NULL;
}

void put(T value, Queue* Q) {
    if (Q==NULL) {
        fprintf(stderr,"error Q==NULL");
    } else if (isEmpty(Q)) {
        Q->first=createNode(value,NULL);
        Q->last=Q->first;
    } else {
        Node* n=createNode(value,NULL);
        Q->last->next=n;
        Q->last=n;
    }
}

T push(Queue* Q) {
    assert(Q!=NULL && !isEmpty(Q));
    Node* first=Q->first;
    if (first->next!=NULL) {
        Q->first = first->next;
    } else {
        Q->first=NULL;
        Q->last=NULL;
    }
    T value = first->val;
    free(first);
    return value;

}

void concat(Queue* Q1, Queue* Q2) {
    if (Q1->last!=NULL) {
        Q1->last->next=Q2->first;
    }
    Q1->last=Q2->last;
    Q2->first=NULL;
    Q2->last=NULL;
}

Queue copyQueue(Queue Q1) {
    Queue Q2;
    Node* n;
    T val;
    for (n=Q1.first; n==NULL; n=n->next) {
        val=push(&Q1);
        put(val,&Q1);
        put(val,&Q2);
    }
    return Q2;
}
