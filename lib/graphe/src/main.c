#include "../headers/genere_graphe.h"
#include "../headers/library.h"
#include "../headers/library_matrice.h"

int main() {
    cree_graphe_oriente_value("./graphe.txt",6,3);
    //graphe* G = createGraphe("./graphe.txt");
    T_LADJ L = charge_graphe("./graphe.txt");
    //printf("Graphe:\n");
    //affiche_graphe(L);
    printf("Parcours profondeur:");
    //parcoursProfondeur(G);
    printf("\nMarquage topologique: ");
    printf("\nreturn %d\n",marquage(&L));
    return 0;
}