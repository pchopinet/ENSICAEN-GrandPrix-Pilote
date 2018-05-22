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
 * @file stack.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"

SNode* createSNode(T value, SNode* next) {
    SNode* n=(SNode*)malloc(sizeof(SNode));
    n->val=value;
    n->next=next;
    return n;
}

Stack* createStack() {
    Stack* S = malloc(sizeof(Stack));
    S->last=NULL;
    S->first=NULL;
    S->size=0;
    return S;
}

int isEmptyStack(Stack* S) {
    return S->last==NULL;
}

void putStack(T value, Stack* S) {
    if (S==NULL) {
        fprintf(stderr,"error S==NULL");
    } else if (isEmptyStack(S)) {
        S->first=createSNode(value,NULL);
        S->last=S->first;
    } else {
        SNode* n=createSNode(value,NULL);
	n->next = S->first;
	S->first = n;
    }
    S->size++;
}

T pushStack(Stack* S) {
    assert(S!=NULL && !isEmptyStack(S));
    SNode* first=S->first;
    if (first->next!=NULL) {
        S->first = first->next;
    } else {
        S->first=NULL;
        S->last=NULL;
    }
    T value = first->val;
    free(first);
    S->size--;
    return value;

}
