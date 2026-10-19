#include "../Include/dataset.h"
#include <stdio.h>

void creationdataset(exemple exempleAddr)
{
    int ligne = exempleAddr.n;
    int colonnes = exempleAddr.dim;

    exempleAddr.exemple = malloc(ligne * sizeof(float *));

    for (int i = 0; i < colonnes; i++)
    {
        exempleAddr.exemple[i] = malloc(colonnes * sizeof(float));
    }
}

void freedataset(exemple exempleAddr)
{
    for (int i = 0; i < exempleAddr.n; i++)
    {
        free(exempleAddr.exemple[i]);
    }
    free(exempleAddr.exemple);
}

int nbChampignons()
{
    int nbChampi = 0;
    FILE *fo = fopen("../data/champignons.csv", "r");

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    char ligne[256];

    while (fgets(ligne, sizeof(ligne), fo) != NULL)
    {
        nbChampi++;
    }

    fclose(fo);
    return nbChampi;
}

void loadData(exemple exe)
{
    exe.n = nbChampignons();
    printf("%d\n", exe.n);
    FILE *fo = fopen("../data/champignons.csv", "r");
    char ligne[256];

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
    }


    while (fgets(ligne, sizeof(ligne), fo) != NULL)
    {
        printf("%s\n", ligne);
    }
    






    fclose(fo);
}


int main(){
    exemple exemple;
    creationdataset(exemple);
    loadData(exemple);



    freedataset(exemple);



    return 0;
}