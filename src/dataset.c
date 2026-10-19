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

int nbDim()
{
    int dim = 0;
    FILE *fo = fopen("../data/champignons.csv", "r");
    char ligne[256];

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
    }
    else
    {
        fgets(ligne, sizeof(ligne), fo);
        const char *delim = ",";

        char *token = strtok(ligne, delim);
        while (token != NULL)
        {
            dim++;
        }
    }

    fclose(fo);
    return dim;
}

int main()
{
    exemple exemple;
    exemple.n = nbChampignons();
    exemple.dim = nbDim();
    
    creationdataset(exemple);

    freedataset(exemple);

    return 0;
}