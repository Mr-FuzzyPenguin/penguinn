#include "penguinn-utils.h"
#include "matrix-utils.h"
#include <math.h>
#include <stdlib.h>

double pseudo_rng(struct rand* r)
{
    double result = (double)(r->seed * r->state % 65536) / 256;
    r->state = (int)((r->seed * result) + 17);

    return result;
}

struct layer* init_layer(int inputs, int neurons, float (*func)(float))
{
    // try to allocate enough space for a new layer
    struct layer* l = malloc(sizeof(struct layer));
    if (l == NULL) {
        return NULL;
    }

    // sample:
    // inputs = 4500
    // neurons = 512
    //   (weight)    (input)   +  (bias)   =
    // (512 x 4500) (4500 x 1) + (512 x 1) =
    // weight: neurons x inputs
    // input: inputs x 1
    // bias: neurons x 1
    // result shape = neurons x 1
    l->input = init_matrix(inputs, 1);
    l->weight = init_matrix(neurons, inputs);
    l->bias = init_matrix(neurons, 1);
    l->activation_func = func;
    l->output = init_matrix(neurons, 1);

    // if not all of the fields successfully allocated, free everything and return NULL
    if (l->input == NULL || l->weight == NULL || l->bias == NULL || l->output == NULL) {
        free_matrix(&l->input);
        free_matrix(&l->weight);
        free_matrix(&l->bias);
        free_matrix(&l->output);
        free(l);
        return NULL;
    }

    // we cannot propagate an error yet
    l->propagating_error_signal = NULL;
    l->error_signal_size = 0;

    // TODO: Set the empty matrix to random values for l->weight

    return l;
}

float silu(float x)
{
    return x / (1.0f + expf(-x));
}

float silu_derivative(float x)
{
    float pwr = expf(-x);
    float a = 1.0f + pwr;

    return (a + x * pwr) / (a * a);
}