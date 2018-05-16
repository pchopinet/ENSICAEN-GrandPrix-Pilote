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
