#include "../include/print.h"

int printTag(Ladj *L) {

    point p;
    //p.boost=5;

    for (p.vx = 0; p.vx < 11; p.vx++) {
        for (p.vy = 0; p.vy < 11; p.vy++) {

            printf("\nTag table vx:%d vy:%d \n\n", p.vx, p.vy);

            for (p.x = 0; p.x < L->height; p.x++) {
                for (p.y = 0; p.y < L->width; p.y++) {
                    printf("%d", *tag(L,p));
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int printDistance(Ladj* L) {

    point p;
    //p.boost=5;

    for (p.vx = 0; p.vx < 11; p.vx++) {
        for (p.vy = 0; p.vy < 11; p.vy++) {

            printf("\nDistance vx:%d vy:%d \n\n", p.vx, p.vy);

            for (p.x = 0; p.x < L->height; p.x++) {
                for (p.y = 0; p.y < L->width; p.y++) {
                    printf("%d", *tag(L,p));
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int printRoute(Track T, Queue* Q) {
    point p;
    int i, j, k=0;
    while (!isEmpty(Q)) {
        p = push(Q);
        T->track[p.x][p.y] = '0';
        k++;
    }

    for (i=0; i<T->height; i++) {
        for (j=0; j<T->width; j++) {
            printf("%c",T->track[i][j]);
        }
        printf("\n");
    }
    printf("\nnb tour : %d\n",k);

    return 0;
}