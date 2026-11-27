#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include <stdio.h>

typedef struct perceptron 
{
int dim; //dimension d'entrée
float *w; //vecteur de poids : tableau de taille dim contenant les poids de chaque entrée (les w_i associés aux x_i)
float b; //biais 
float lr; //taux d'apprentissage
} perceptron;

Perceptron *perceptron_create(int dim, double lr);
void perceptron_free(Perceptron *p);

#endif