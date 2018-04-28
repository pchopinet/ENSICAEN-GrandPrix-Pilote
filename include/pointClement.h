#ifndef POINT_CLEMENT_H
#define POINT_CLEMENT_H

typedef struct point {
    int x;
    int y;
    int vx;
    int vy;
} point;

int pointIn(point p,int x,int y);

#endif