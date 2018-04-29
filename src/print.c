#include "../include/print.h"

int printTag(Ladj *L) {

    int i, j, k, l;

    printf("%d\n", L->tag[15][31][7][0]);

    for (k = 0; k < 11; k++) {
        for (l = 0; l < 11; l++) {

            printf("\nTag table vx:%d vy:%d \n\n", k - 5, l - 5);

            for (i = 0; i < L->height; i++) {
                for (j = 0; j < L->width; j++) {
                    printf("%d", L->tag[i][j][k][l]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int printDistance(Ladj* L) {

    int i, j, k, l;


    for (k = 0; k < 11; k++) {
        for (l = 0; l < 11; l++) {

            printf("\nDistance vx:%d vy:%d \n\n", k - 5, l - 5);

            for (i = 0; i < L->height; i++) {
                for (j = 0; j < L->width; j++) {
                    printf("%d", L->tag[i][j][k][l]);
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