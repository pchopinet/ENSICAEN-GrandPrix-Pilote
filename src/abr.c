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
#include"../include/abr.h"

nodeABR * insere(nodeABR* n, element x) {
  if (n == NULL) {
    n = (nodeABR*) malloc(sizeof(nodeABR));
    n->val = x;
    n->left = NULL;
    n->right = NULL;
  } else if (x == n->val) {
  printf("%d est deja dans l'arbre\n",x);
} else if (x < n->val) {
    n->left = insere(n->left,x);
  } else {
    n->right = insere(n->right,x);
  }
  return(n);
}

void affiche_arbre(nodeABR* n, int col) {
  int i;
  if (n) {
    affiche_arbre(n->right,col+1);
    for (i=0; i<col; i++) {
      printf("   ");
    }
    printf("%d\n",n->val);
    affiche_arbre(n->left,col+1);
    }
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

int preffix(nodeABR* A) {
  int nodeNumber=0;
  if (A) {
    printf("%d  ",A->val);
    nodeNumber += preffix(A->left);
    nodeNumber += preffix(A->right);
    nodeNumber++;
  }
  return nodeNumber;
}

int suffix(nodeABR* A) {
  int nodeNumber=0;
  if (A) {
    nodeNumber += suffix(A->left);
    nodeNumber += suffix(A->right);
    printf("%d  ",A->val);
    nodeNumber++;
  }
  return nodeNumber;
}

int parcoursLargeur(nodeABR* A) {
  int nodeNumber=0;
  Queue Q = createQueue();
  put(A,&Q);
  nodeABR* B=NULL;
  while (Q.last!=NULL) {
    nodeNumber++;
    B=pop(&Q);
    printf("%d  ",B->val);
    if(B->left) {
      put(B->left,&Q);
    }
    if(B->right) {
      put(B->right,&Q);
    }
  }
  return nodeNumber;
}

//int extractMin()
