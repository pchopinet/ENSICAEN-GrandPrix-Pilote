#include "../include/print.h"

int printTag(Ladj *L) {

    point p;
    //p.boost=5;

    for (p.vx = -5; p.vx < 6; p.vx++) {
        for (p.vy = -5; p.vy < 6; p.vy++) {

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

int printRoute(Track T, Stack* S) {
    point p;
    int i, j, k=0;
    while (!isEmptyStack(S)) {
        p = pushStack(S);
        T->track[p.x][p.y] = '0';
        k++;

        //printf("p: %d %d %d %d\n",p.x,p.y,p.vx,p.vy);
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