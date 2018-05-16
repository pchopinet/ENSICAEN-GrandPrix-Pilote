#ifndef STACK_H
#define STACK_H

#include "../../include/pointClement.h"

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
