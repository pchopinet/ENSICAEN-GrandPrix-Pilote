
//
// Created by clabonne on 04/04/18.
//

#ifndef UNTITLED1_LADJ_H
#define UNTITLED1_LADJ_H
#include <stdio.h>
#include <stdlib.h>


typedef struct t_cellule {
    int extremite;
    float valuation;
    struct t_cellule *suivant;
} T_CELLULE;

typedef struct t_ladj {
    int nbsom, nbar;
    T_CELLULE **tab;
    int* nbpred;
    int* marquage;
} T_LADJ;

T_CELLULE *creer_cellule(int, float, T_CELLULE *);
void affiche_liste(T_CELLULE *);
T_LADJ init_ladj(int, int);
void affiche_graphe(T_LADJ);
T_LADJ charge_graphe(char *);
/*
void main(int, char **);*/
#endif
