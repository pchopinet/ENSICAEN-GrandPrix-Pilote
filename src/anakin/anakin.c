//
// Created by chopinet on 07/04/18.
//


#include "../../include/track/track.h"

int main() {

    Track t = initTrack();
    FILE *f = fopen("../anakin.log", "w");
    fprintf(f, "%d %d %d\n", t->height, t->width, t->fuel);

    for (int i = 0; i < t->height; i++) {
        printf("%d : ",i);
        for (int j = 0; j < t->width; j++) {
            printf("%c", t->track[i][j]);
        }
        printf("\n");
    }
}