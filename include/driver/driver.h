//
// Created by chopinet on 10/04/18.
//

#ifndef ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
#define ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H

typedef struct driver_t {
    int x;
    int y;
    int vx;
    int vy;
    int fuel;
} *Driver;

void move(Driver p, int ax, int ay);


#endif //ENSICAEN_GRANDPRIX_PILOTE_PILOTE_H
