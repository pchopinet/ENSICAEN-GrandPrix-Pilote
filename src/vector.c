//
// Created by pierre on 27/04/18.
//

#include <stdlib.h>
#include "../include/vector.h"

Vector newVector(int x, int y) {
    Vector v = malloc(sizeof(struct vector_t));
    v->x = x;
    v->y = y;
    return v;
}
