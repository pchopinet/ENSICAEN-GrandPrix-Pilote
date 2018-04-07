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
 * @version 0.0.1 / 21-03-2018
 */

/**
 * @file genere_graphe.h
 */

#ifndef __GENERE_GRAPHE_H
#define __GENERE_GRAPHE_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSOMMET 	250
#define MAXVALUATION 	20.0
#define MAXSUCC		10

typedef struct {
           int nbsom;
           int nbarc;
	   float **matrice; /* matrice d'adjacence */
	   } graphe;

typedef struct {	
	 int *pere;
	 int nbelements;
	 int nbclasses; } t_ens;	 

void init_graphe(int, int, graphe*);
void cree_graphe_oriente_value(char*, int, int);
void cree_graphe_oriente_non_value(char*, int , int);
void cree_graphe_non_oriente_value(char*, int, int);
void cree_graphe_non_oriente_non_value(char*, int, int);
void cree_graphe_topo_value(char*, int, int);
void cree_graphe_topo_non_value(char*, int, int);
void init_ens(int, t_ens*);
int trouver(int, t_ens*);
void reunir(int, int, t_ens*);
void cree_graphe_connexe_non_value(char*, int, int);
void cree_graphe_connexe_value(char*, int, int);

#endif
