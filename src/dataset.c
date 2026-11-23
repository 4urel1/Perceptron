#include "../Include/dataset.h"
#include <stdio.h>

data creationdataset(data exempleAddr)
{
    int ligne = exempleAddr.n;
    int colonnes = exempleAddr.dim + 1;

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

int nbLignes(char *chemin)
{
    int nbLigne = 0;
    FILE *fo = fopen(chemin, "r");

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier dans nbLignes\n");
        perror(chemin);
        return -1;
    }

    char ligne[256];

    while (fgets(ligne, sizeof(ligne), fo) != NULL)
    {
        if (!(ligne[0] == '\n' || ligne[0] == '\r'))
            nbLigne++;
    }

    fclose(fo);
    return nbLigne;
}

int nbDim(char *chemin)
{
    int dim = 0;
    FILE *fo = fopen(chemin, "r");
    char ligne[256];

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier dans la fonction nbDim\n");
        perror(chemin);
        return -1;
    }
    else
    {
        fgets(ligne, sizeof(ligne), fo);
        const char *delim = ",\r\n";

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

int remplirDataset(data *data, char *chemin)
{

    int ligne = 0;
    int colonne = 0;
    FILE *fo = fopen(chemin, "r");
    char caracteres[256];

    if (fo == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    else
    {
        while (fgets(caracteres, sizeof(caracteres), fo) != NULL)
        { // debut du remplissage.
            if (!(caracteres[0] == '\n' || caracteres[0] == '\r'))
            {
                const char *delim = ",\r\n";

                char *token = strtok(caracteres, delim);
                colonne = 0;
                while (token != NULL)
                {
                    if (colonne >= data->dim + 1)
                    {
                        printf("trop de valeurs dans la ligne\n");
                        fclose(fo);
                        return -1;
                    }
                    data->exemple[ligne][colonne] = (float)atof(token);
                    token = strtok(NULL, delim);
                    colonne++;
                }

                if (colonne < data->dim + 1)
                {
                    printf("pas assez de valeurs dans la ligne\n");
                    fclose(fo);
                    return -1;
                }
                ligne++;
            }
        }
    }
    fclose(fo);
    return 0;
}

void afficheData(data data)
{
    int ligne = data.n;
    int colonne = data.dim;
    for (int i = 0; i < ligne; i++)
    {
        printf("[");
        for (int j = 0; j < colonne; j++)
        {
            printf("%.2f, ", data.exemple[i][j]);
        }
        printf("%.2f]\n", data.exemple[i][colonne]);
    }
}

int main(void)
{
    data data;
    char *chemin = "data/ou.csv";
    data.n = nbLignes(chemin);
    data.dim = nbDim(chemin) - 1;

    if (data.n <= 0 || data.dim <= 0)
        return 1;

    data = creationdataset(data);

    if (remplirDataset(&data, chemin) == -1)
    {
        freedataset(data);
        return -1;
    }
    else
        afficheData(data);

    freedataset(data);

    return 0;
}