#include <stdio.h>
#include <stdlib.h>
typedef struct exemple
{
    /* data */
    int n; //nb d'exemples
    int dim; //nombre de caractéristiques
    float **exemple; //caratéristiques du chapignons
}exemple;

void creation();
//alloue dynamiquement la mémoire

int loadFile();
//fonction qui va chercher les données dans champignons.csv et compte le nombre de lignes que le fichier a