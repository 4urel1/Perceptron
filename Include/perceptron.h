#include <stdio.h>

typedef struct perceptron 
{
int dim; //dimension d'entrée
float poids[dim]; //vecteur de poids : tableau de taille dim contenant les poids de chaque entrée (les w_i associés aux x_i)
float biais; //biais 
float lr; //taux d'apprentissage
} perceptron;