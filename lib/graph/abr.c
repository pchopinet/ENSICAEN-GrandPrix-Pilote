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
 * @version 0.0.1 / 31-01-2018
 */

/**
 * @file abr.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"abr.h"

nodeABR *insert(nodeABR *n, point p, int x) {
  if (n == NULL) {
    n = (nodeABR *) malloc(sizeof(nodeABR));
    n->weight = x;
    n->point = p;
    n->left = NULL;
    n->right = NULL;
  } else if (x < n->weight) {
    n->left = insert(n->left, p, x);
  } else {
    n->right = insert(n->right, p, x);
  }
  return n;
}

int leefNumber(nodeABR* A) {
  int leef=0;
  if (A->left!=NULL) {
    leef = leefNumber(A->left);
  }
  if (A->right!=NULL) {
    leef = leef+leefNumber(A->right);
  } else if (A->left==NULL) {
    return 1;
  }
  return leef;
}

void affiche_arbre(nodeABR* n, int col) {
    int i;
    if (n) {
        affiche_arbre(n->right,col+1);
        for (i=0; i<col; i++) {
            printf("   ");
        }
        printf("%d\n",n->weight);
        affiche_arbre(n->left,col+1);
    }
}

/*nodeABR nodeMin(nodeABR t) {
    if (t->left == NULL) {
        return t;
    } else {
        return nodeMin(t->left);
    }
}*/

nodeABR* extractMin(nodeABR* p) {

  while (p->left != NULL) {
      p = p->left;
  }
      extractMin(p->left);
    return p;
}
