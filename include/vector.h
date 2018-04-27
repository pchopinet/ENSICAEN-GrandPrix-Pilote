//
// Created by pierre on 27/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
#define ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H

typedef struct vector_t {
    int x;
    int y;
} *Vector;

Vector newVector(int x,int y);


#endif //ENSICAEN_GRANDPRIX_PILOTE_VECTOR_H
