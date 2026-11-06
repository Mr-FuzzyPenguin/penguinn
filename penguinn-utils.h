#ifndef PENGUINN_UTILS_H
#define PENGUINN_UTILS_H

#include "matrix-utils.h"

struct layer {
    struct matrix* input;
    struct matrix* weight;
    struct matrix* bias;
    struct matrix* output;
    float (*activation_func)(float);
    float* propagating_error_signal;
    int error_signal_size;
};

struct layer* init_layer(int inputs, int neurons, float (*func)(float), long* r);

// I need to specify an input matrix. BE CAREFUL ABOUT FREEING THE INPUT!!
void stimulate_layer(struct matrix* m, struct layer** l);
void run_layer(struct layer** l);

long pseudo_rng(long* r);
float silu(float x);
float silu_derivative(float x);
#endif