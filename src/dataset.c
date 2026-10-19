#include "../include/dataset.h"
#include <stdio.h>

void creation();

int nbChapingnons(){
    int nbChampi = 0;
    FILE *fo = fopen("champignons.csv", "r");

    if (fo == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    char ligne[255];

    while (fgets(ligne, sizeof(ligne), fo) != NULL) {
        nbChampi++;
    }


    fclose(fo);
    return nbChampi;
}

void loadData();


