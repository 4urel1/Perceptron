#include "../Include/dataset.h"
#include <stdio.h>

data creationdataset(data exempleAddr)
{
    int ligne = exempleAddr.n;
    int colonnes = exempleAddr.dim;

    exempleAddr.exemple = malloc(ligne * sizeof(float *));

    for (int i = 0; i < ligne; i++)
    {
        exempleAddr.exemple[i] = malloc(colonnes * sizeof(*exempleAddr.exemple[i]));
    }
    return exempleAddr;
}

void freedataset(data exempleAddr)
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
            token = strtok(NULL, delim);
        }
    }

    fclose(fo);
    return dim;
}

void remplirDataset(data data)
{

    int ligne = data.n;
    int colonne = data.dim;
    FILE *fo = fopen("../data/champignons.csv", "r");
    char caracteres[256];

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
    }
    else
    {
        fgets(caracteres, sizeof(caracteres), fo);
        const char *delim = ",";

        char *token = strtok(caracteres, delim);

        for (int i = 0; i < ligne; i++)
        {
            for (int j = 0; j < colonne; j++)
            {

                data.exemple[i][j] = (float)atof(token);
                token = strtok(NULL, delim);
            }
        }
    }
}

int main(void)
{
    data data;
    data.n = nbChampignons();
    data.dim = nbDim();

    if (data.n <= 0 || data.dim <= 0)
        return 1;

    data = creationdataset(data);

    freedataset(data);

    return 0;
}