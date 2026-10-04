#ifndef PENGUINN_UTILS_H
#define PENGUINN_UTILS_H

#include "matrix-utils.h"

struct rand {
    int seed;
    int state;
};

struct layer {
    struct matrix* input;
    struct matrix* weight;
    struct matrix* bias;
    struct matrix* output;
    float (*activation_func)(float);
    float* propagating_error_signal;
    int error_signal_size;
};

struct layer* init_layer(int inputs, int neurons, float (*func)(float));
double pseudo_rng(struct rand* r);
float silu(float x);
float silu_derivative(float x);
#endif