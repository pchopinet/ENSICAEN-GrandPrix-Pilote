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
    Stack* Q = malloc(sizeof(Stack));
    Q->last=NULL;
    Q->first=NULL;
    return Q;
}

int isEmptyStack(Stack* Q) {
    return Q->last==NULL;
}

void putStack(T value, Stack* Q) {
    if (Q==NULL) {
        fprintf(stderr,"error Q==NULL");
    } else if (isEmptyStack(Q)) {
        Q->first=createSNode(value,NULL);
        Q->last=Q->first;
    } else {
        SNode* n=createSNode(value,NULL);
	n->next = Q->first;
	Q->first = n;
    }
}

T pushStack(Stack* Q) {
    assert(Q!=NULL && !isEmptyStack(Q));
    SNode* first=Q->first;
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
