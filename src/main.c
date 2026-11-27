#include <stdio.h>
#include "dataset.h"
#include "perceptron.h"

int main(void) {
    /* 1. Création en mémoire */
    Dataset *d = dataset_create(10, 4);
    Perceptron *p = perceptron_create(4, 0.1);

    /* 2. Vérification que les allocations ont réussi */
    if (d == NULL || p == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        dataset_free(d);
        perceptron_free(p);
        return 1;
    }

    /* 3. Petit test d'écriture dans la matrice et affichage */
    d->X[0][0] = 42.5;
    d->labels[0] = 1;

    printf("Dataset OK : n=%d, dim=%d, X[0][0]=%.1f, label[0]=%d\n",
           d->n, d->dim, d->X[0][0], d->labels[0]);
    printf("Perceptron OK : dim=%d, lr=%.2f, bias=%.2f\n",
           p->dim, p->lr, p->bias);

    /* 4. Libération propre de toute la mémoire */
    dataset_free(d);
    perceptron_free(p);
    return 0;
}

