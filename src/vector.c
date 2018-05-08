//
// Created by pierre on 27/04/18.
//

#include <stdlib.h>
#include "../include/vector.h"
#include <math.h>

struct vector_t {
    int x;
    int y;
    double norm;
};

double norm(int x, int y);


Vector newVector(int x, int y) {
    Vector v = malloc(sizeof(struct vector_t));
    v->x = x;
    v->y = y;
    v->norm = norm(x, y);
    return v;
}

double VectorGetNorm(Vector this) {
    return this->norm;
}

void VectorAdd(Vector this, Vector v) {
    this->x += v->x;
    this->y += v->y;
}

int VectorX(Vector this) {
    return this->x;
}

int VectorY(Vector this) {
    return this->y;
}

Vector VectorDiff(Vector v1, Vector v2) {
    return newVector(v2->x - v1->x, v2->y - v1->y);

}

double norm(int x, int y) {
    return ((double) sqrt(x * x + y * y));
}
