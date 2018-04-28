#include "../include/pointClement.h"

int pointIn(point p,int x,int y) {
    return (p.x>=0 && p.y>=0 && p.x<x && p.y<y);
}