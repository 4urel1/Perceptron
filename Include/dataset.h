#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct data
{
    /* data */
    int n;           // nb d'exemples
    int dim;         // nombre de caractéristiques
    float **exemple; // caratéristiques du chapignons
} data;

void creation();
// alloue dynamiquement la mémoire

int nbLignes();
// fonction qui va chercher les données dans champignons.csv et compte le nombre de lignes que le fichier a

int nbDim();
//compte le nombre de colonnes (dim) de champignons.csv

int main();
//fonction principale du dataset

void remplirDataset(data* data, char* chemin);
//charge les données des csv pour les mettes dans data