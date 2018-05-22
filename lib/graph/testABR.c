//
// Created by clabonne on 22/05/18.
//

#include "abr.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    point p;
    p.x = 1;
    p.y = 1;
    p.vx = 1;
    p.vy = 1;
    nodeABR* a = insert(a,p,8 );
    a = insert(a,p,5);
    a = insert(a,p,2);
    a = insert(a,p,5);
    affiche_arbre(a, 2);
    printf("%d\n", leefNumber(a));
    extractMin(a);

    affiche_arbre(a, 2);
}