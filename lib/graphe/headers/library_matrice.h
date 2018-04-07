#ifndef TP4_LIBRARY_H
#define TP4_LIBRARY_H

#include "genere_graphe.h"
#include "file.h"

graphe* createGraphe (char*);
void printMatrix (graphe*);
int recursProf(graphe*, int*, int);
void parcoursProfondeur(graphe*);
void parcoursLargeur(graphe*);


#endif