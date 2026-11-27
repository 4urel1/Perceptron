#include "../Include/perceptron.h"
#include <stdlib.h>
#include <math.h>

perceptron *perceptron_create(int dim, double lr) {
    if (dim <= 0 || lr <= 0.0) {
        return NULL;
    }

    perceptron *p = malloc(sizeof(perceptron));
    if (p == NULL) {
        return NULL;
    }

    p->w = calloc((size_t)dim, sizeof(double));
    if (p->w == NULL) {
        free(p);
        return NULL;
    }

    p->b = 0.0;
    p->dim = dim;
    p->lr = lr;

    return p;
}

void perceptron_free(perceptron *p) {
    if (p == NULL) {
        return;
    }

    free(p->w);
    free(p);
}


float sigmoide(float z)
{
    return 1 / (1 + exp(-z));
}

float prediction(float *x, perceptron *p)  
{

    float z;
    for(int i=0; i<p->dim; i++)
    {
        z=p->w[i]*x[i]+p->b;
    }
    return sigmoide(z);
}

float apprentissage(float *x, *p, float y )
{
    for (int j=0; j<p->dim, j++)
    {
        p->w[j] = w[j]+ p->lr * (x[dim]-y);
    }
    
}