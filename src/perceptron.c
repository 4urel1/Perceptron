#include <stdio.h>
#include <stdlib.h>
#include <perceptron.h>

void création(){
    struct perceptron *p = malloc(sizeof(struct perceptron));
    for (int i=0;i<dim;i++){
        poids[i]=0;
    }
    biais = 0;
}

void libération(){
    free(p);
}