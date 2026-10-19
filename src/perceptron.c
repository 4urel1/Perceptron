#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Include/perceptron.h"

void creation(){
    struct perceptron *p = malloc(sizeof(struct perceptron));
    for (int i=0;i<dim;i++){
        w[i]=0;
    }
    biais = 0;
    lr = 0.1;
}

void libération(){
    free(p);
}

void sigmoide(int z){
    z = 1 / (1 + exp(-z));
}

float prediction(struct perceptron, float x[dim], int z){
    for (int i=0; i<dim ; i++){
        z = x[i]*w[i];
    }
    z = z + b;
    z = sigmoide(z);
    return z;
}

void maj(struct perceptron, int label, float x[dim]){
    for (int i = 0; i<dim, i++){
        w[i]= w[i] + lr * x[i] * (label - prediction(perceptron, x[dim], z));
    }
}

