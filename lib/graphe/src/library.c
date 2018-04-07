//
// Created by clabonne on 04/04/18.
//

#include "../headers/library.h"

int marquage(T_LADJ* L) {
    int i;
    int n=0;
    int sommet;
    int val;
    Queue Q = createQueue();
    int* marquage = calloc(L->nbsom,sizeof(int));

    L->marquage=calloc(L->nbsom,sizeof(int));

    for (i=0; i<L->nbsom; i++) {
        if (L->nbpred[i]==0) {
            put(i,&Q);
        }
    }

    if(isEmpty(Q)){
        free(L->marquage);
        printf("\nError: circuit!\n");
        return 1;
    }

    while (!isEmpty(Q)) {
        sommet = push(&Q);
        marquage[sommet]=1;
        printf("%d",sommet);
        L->marquage[n]=sommet;
        n++;
        for (T_CELLULE* cell = L->tab[sommet];
             cell!=NULL; cell=cell->suivant) {
            if (marquage[cell->extremite]==0) {
                val = cell->extremite;
                L->nbpred[val]--;
                if (L->nbpred[val]==0) {
                    put(val, &Q);
                }
            } else {
                free(L->marquage);
                printf("\nError: circuit!\n");
                return 2;
            }
        }
    }

    if(n!=L->nbsom){
        free(L->marquage);
        printf("\nError: circuit!\n");
        return 3;
    }

    printf("\n");
    return 0;
}