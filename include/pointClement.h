#ifndef POINT_CLEMENT_H
#define POINT_CLEMENT_H


typedef struct point {
    int x;
    int y;
    int vx;
    int vy;
    int boost;
} point;

int ptEqual(point p, point q);

#endif