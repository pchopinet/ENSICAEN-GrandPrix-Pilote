#include "../include/dijkstra.h"

Dnode* createDnode(int tot, point p, Dnode* next) {
    Dnode* n = malloc(sizeof(Dnode));
    n->totFuel = tot;
    n->point = p;
    n->next = next;
    return n;
}

List* createList() {
    List* L = malloc(sizeof(List));
    L->first = NULL;
    return L;
}

void putInList(List* L, point p, int tot) {
    Dnode *n;
    Dnode *tmp;
    if (L->first == NULL) {
        L->first = createDnode(tot, p, NULL);
    } else {
        n = L->first;
        while (n->next != NULL && n->next->totFuel < tot) {
            n = n->next;
        }
        tmp = n->next;
        n->next = createDnode(tot, p, tmp);
    }
}

point getMin(List* L) {
    Dnode* tmp;
    if (L->first == NULL) {
        perror("l->first NULL");
    }
    point p = L->first->point;
    tmp =  L->first;
    L->first = L->first->next;
    free(tmp);
    return p;
}

int removeFromList(point p, List* L) {
    Dnode* n;
    Dnode* tmp;
    if (L->first == NULL) {
        perror("L->first null in remove");
    }
    if (ptEqual(L->first->point, p)) {
        tmp =  L->first;
        L->first = L->first->next;
        free(tmp);
    } else {
        n = L->first;
        while (n->next != NULL && !ptEqual(n->next->point, p)) {
            n = n->next;
        }
        if (n->next == NULL) {
            perror("n->next null in remove");
        }
        tmp = n->next;
        n->next = n->next->next;
        free(tmp);
    }
    return 0;
}

void changeTotFuel(List* L, point p, int tot) {
    removeFromList(p,L);
    putInList(L, p, tot);
}