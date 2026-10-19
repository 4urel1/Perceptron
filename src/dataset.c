#include "../Include/dataset.h"
#include <stdio.h>

void creationdataset(exemple exempleAddr){
    int ligne = exempleAddr.n;
    int colonnes = exempleAddr.dim;

    exempleAddr.exemple = malloc(ligne * sizeof(float *));

    for (int i = 0; i < colonnes; i++){
        exempleAddr.exemple[i] = malloc(colonnes * sizeof(float));
    }
}

void freedataset(exemple exempleAddr){
    for (int i = 0; i < exempleAddr.n; i++){
        free(exempleAddr.exemple[i]);
    }
    free(exempleAddr.exemple);
}

int loadFile(){
    int nbChampi = 0;
    FILE *fo = fopen("champignons.csv", "r");

    if (fo == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    char ligne[255];

    while (fgets(ligne, sizeof(ligne), fo) != NULL) {
        nbChampi++;
        printf("%s", ligne[nbChampi]);
    }


    fclose(fo);
    return nbChampi;
}

void loadData();


