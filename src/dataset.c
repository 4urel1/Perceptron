#include <stdio.h>
#include "dataset.h"
#include <stdlib.h>
#include <string.h>

Dataset *dataset_create(int n, int dim) {
    if (n <= 0 || dim <= 0) {
        return NULL;
    }

    Dataset *d = malloc(sizeof(Dataset));
    if (d == NULL) {
        return NULL;
    }

    d->n = n;
    d->dim = dim;
    d->X = NULL;
    d->labels = NULL;

    d->X = calloc((size_t)n, sizeof(double *));
    if (d->X == NULL) {
        free(d);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        d->X[i] = calloc((size_t)dim, sizeof(double));
        if (d->X[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(d->X[j]);
            }
            free(d->X);
            free(d);
            return NULL;
        }
    }

    d->labels = calloc((size_t)n, sizeof(int));
    if (d->labels == NULL) {
        dataset_free(d);
        return NULL;
    }

    return d;
}

void dataset_free(Dataset *d) {
    if (d == NULL) {
        return;
    }

    if (d->X != NULL) {
        for (int i = 0; i < d->n; i++) {
            free(d->X[i]);
        }
        free(d->X);
    }

    free(d->labels);
    free(d);
}

/*etape 2*/
int count_features(const char *line){
    int compte = 0;
    while (*line != '\0' && *line != '\n') {
        if (*line== ',') {
            compte++;
            
        }
        line++;
    }
    return compte;
}

Dataset *dataset_load(const char *filename) {

    /* 1. ouvrir le fichier ; si fopen retourne NULL -> retourner NULL */
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    /* 2. lire la première ligne avec fgets ; si échec -> libérer la mémoire et retourner NULL */
    char line[1024];
if (fgets(line, sizeof(line), file) == NULL) {
    fclose(file);
    return NULL;
}
/* 3. compter le nb de vigurles; si le nombre est égal ou inferieur à 0 -> fermer le fichier et retourner NULL */
   int dim = count_features(line);
if (dim <= 0) {
    fclose(file);
    return NULL; 
   
}
/* 4. n = compter le nombre de lignes restantes dans le fichier ; si echec -> libérer la mémoire et retourner NULL */
/* vérifier en relisant le fichier que chaque ligne a le bon nombre de colonnes; si echec -> libérer la mémoire et retourner NULL */
rewind(file);
int n = 0;
while (fgets(line, sizeof(line), file) != NULL) {
    if (line[0] != '\n' && line[0] != '\0') {
        n++;
    }
}
if (n == 0) {
    fclose(file);
    return NULL;
}
/* 5. créer le dataset avec les dimensions (n et dim); si echec -> libérer la mémoire et retourner NULL */
Dataset *d = dataset_create(n, dim);
if (d == NULL) {
    fclose(file);
    return NULL;
}
/* 6 fermer le fichier et libérer la mémoire allouée par des erreurs; si echec -> libérer la mémoire et retourner NULL */   
if 
fclose(file);
dataset_free(d);
return NULL;
}
 