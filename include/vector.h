//
// Created by pierre on 27/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
#define ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H

typedef struct vector_t *Vector;

Vector newVector(int x, int y);

double VectorGetNorm(Vector this);

int VectorGetX(Vector this);

int VectorGetY(Vector this);


#endif //ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
