#include "../include/genere_graphe.h"
#include "../include/library.h"

int main() {
    cree_graphe_oriente_value("./graph.txt",6,3);
    Ladj L = loadGraph("./graph.txt");
    printf("\nMarquage topologique: ");
    printf("\nreturn %d\n",tagging(&L));
    return 0;
}