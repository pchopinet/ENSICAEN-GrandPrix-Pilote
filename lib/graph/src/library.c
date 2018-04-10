//
// Created by clabonne on 04/04/18.
//

#include "../include/library.h"
/*
int tagging(Ladj* L) {
    int i;
    int n=0;
    int node;
    int val;
    Queue Q = createQueue();
    int* flag = calloc(L->nbNode,sizeof(int));

    L->tag=calloc(L->nbNode,sizeof(int));

    for (i=0; i<L->nbNode; i++) {
        if (L->indegree[i]==0) {
            put(i,&Q);
        }
    }

    if(isEmpty(Q)){
        free(L->tag);
        printf("\nError: circuit!\n");
        return 1;
    }

    while (!isEmpty(Q)) {
        node = push(&Q);
        flag[node]=1;
        printf("%d",node);
        L->tag[n]=node;
        n++;
        for (Cell* C = L->tab[node];
             C!=NULL; C=C->next) {
            if (flag[C->head]==0) {
                val = C->head;
                L->indegree[val]--;
                if (L->indegree[val]==0) {
                    put(val, &Q);
                }
            } else {
                free(L->tag);
                printf("\nError: circuit!\n");
                return 2;
            }
        }
    }

    if(n!=L->nbNode){
        free(L->tag);
        printf("\nError: circuit!\n");
        return 3;
    }

    printf("\n");
    return 0;
}*/