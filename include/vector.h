//
// Created by pierre on 27/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
#define ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H

typedef struct vector_t *Vector;

Vector newVector(int x, int y);

double VectorGetNorm(Vector this);

int VectorX(Vector this);

int VectorY(Vector this);

void VectorAdd(Vector this, Vector v);

Vector VectorDiff(Vector v1, Vector v2);

#endif //ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
