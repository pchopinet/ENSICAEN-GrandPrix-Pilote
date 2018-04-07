
#include "../../include/trach.h"

#include <stdlib.h>

int initTrack(Track t){
    t = malloc(sizeof(struct track_t));
    if(t==NULL){
        exit(1);
    }
    readHeader(t);
    readTrack(t);
    return 0;
}

int readHeader(Track t){
    scanf("%d %d %d",&t->height,&t->width, &t->fuel);
    if (t->heigth == 0 || t->width == 0 || t->fuel == 0){
        return 1;
    }

    return 0;
}

int readTrack(Track t){
    int i,j;
    t->track = malloc(sizeof(char)*t->height);
    for (i=0; i<t->height;i++) {
        t->track[i]=malloc(sizeof(char)*t->width)
        for (j=0; j<t->width; j++) {
            scanf("%c",&t->track[i][j]);
        }
    }
    return 0;
}
