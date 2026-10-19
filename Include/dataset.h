#include <stdio.h>



typedef struct dataChampignons
{
    // x1,x2,x3 et x4 doivent être compris entre 0 et 255. Label est à 0 pour comestible ou 1 pour non comestible.
    int x1; //diamètre du chapeau
    int x2; //hauteur du pied
    int x3; //indice colorimétrique du chapeau (plus la valeur est haute, plus la couleur est vive)
    int x4; //diamètre du chapeau
    int label; //0 pour comestible ou 1 pour non comestible
};

typedef struct dataset
{
    /* data */
    int n; //nb d'exemples
    int dim; //nombre de caractéristiques
    dataChampignons caracteristiques; //caratéristiques du chapignons
};

void creation();
//alloue dynamiquement la mémoire

void nbChapingnons();
//fonction qui va chercher les données dans champignons.csv et compte le nombre de lignes que le fichier a