#include "../headers/library_matrice.h"
#include "../headers/genere_graphe.h"

/**
 * library pour les matrices d'adjancences
 */


graphe* createGraphe (char* filePath) {
    int n,m,i;
    FILE* f = fopen(filePath,"rw");
    graphe* G = malloc(sizeof(graphe));
    fscanf(f,"%d %d",&n,&m);
    init_graphe(n,m,G);
    for (i=0; i<G->nbarc; i++) {
        fscanf(f,"%d %d",&n,&m);
        G->matrice[n][m]=1;
        G->matrice[m][n]=1;
    }
    return G;
}

void printMatrix (graphe* G) {
    int i,j;
    for (i=0; i<G->nbsom; i++) {
        for (j=0; j<G->nbsom; j++) {
            printf("%.f ",G->matrice[i][j]);
        }
        printf("\n");
    }
}

int recursProf(graphe* G,int* tab, int s) {
    int i;
    int n=0;
    tab[s]=1;
    printf("%d ",s);
    for (i=0; i<G->nbsom; i++) {
        if (G->matrice[s][i]==1 && tab[i]==0) {
            n += recursProf(G,tab,i);
        }
    }
    return n+1;
}
void parcoursProfondeur(graphe* G) {
    printf("\n");
    int i;
    int* tab = calloc((size_t) G->nbsom, sizeof(int));
    for (i=0; i<G->nbsom; i++){
        if(tab[i]==0) {
            printf("\t %d noeuds",recursProf(G,tab,i));
            printf("\n");
        }
    }
}

void parcoursLargeur(graphe* G) {
    int n=0;
    int i,j,m;
    int* sommet = calloc((size_t)G->nbsom,sizeof(int));
    Queue Q = createQueue();
    printf("\n");
    for (j=0; j<G->nbsom; j++) {
        if (sommet[j]==0) {
            m=1;
            put(j, &Q);
            sommet[j]=1;
            while (!isEmpty(Q)) {
                n = push(&Q);
                printf("%d ",n);
                for (i=0; i<G->nbsom; i++) {
                    if(G->matrice[n][i] && sommet[i]==0) {
                        put(i,&Q);
                        sommet[i]=1;
                        m++;
                    }
                }
            }
            printf("\t %d noeuds\n",m);
        }
    }
}