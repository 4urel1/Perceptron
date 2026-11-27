#include <stdio.h>
#include "../Include/dataset.h"
#include "../Include/perceptron.h"

int main(void) {
  
    data *d = dataset_create(10, 4);
    perceptron *p = perceptron_create(4, 0.1);

    if (d == NULL || p == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        dataset_free(d);
        perceptron_free(p);
        return 1;
    }

    d->exemple[0][0] = 42;
    d->exemple[p->dim] = 1;

    printf("Dataset OK : n=%d, dim=%d, X[0][0]=%.1f, label[0]=%d\n",
           d->n, d->dim, d->exemple[0][0], d->exemple[p->dim]);
    printf("Perceptron OK : dim=%d, lr=%.2f, biais=%.2f\n",
           p->dim, p->lr, p->b);

    dataset_free(d);
    perceptron_free(p);
    return 0;
}