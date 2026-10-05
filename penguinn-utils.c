#include "penguinn-utils.h"
#include "matrix-utils.h"
#include <math.h>
#include <stdlib.h>

double pseudo_rng(struct rand* r)
{
    long seed_state = r->seed * r->state;
    double result = ((double)(seed_state % 65535)) / 65534.0;
    r->state = (long)(seed_state + 17);

    return result;
}

struct layer* init_layer(int inputs, int neurons, float (*func)(float), struct rand* r)
{
    // try to allocate enough space for a new layer
    struct layer* l = malloc(sizeof(*l));
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

    l->input = NULL; // NULL for now. Not provided upon initialization
    l->weight = init_matrix(neurons, inputs);
    l->bias = init_matrix(neurons, 1);
    l->activation_func = func;
    l->output = NULL; // NULL for now. Not updated until run_layer() is called

    // if not all of the fields successfully allocated, free everything and return NULL
    if (l->weight == NULL || l->bias == NULL) {
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

    // NOTE: This sets the empty matrix to random values for l->weight
    for (int i = 0; i < neurons; i++) {
        // remember: inputs are columns, outputs are rows
        for (int j = 0; j < inputs; j++) {
            l->weight->matrix_ptr[i][j] = (float)(pseudo_rng(r)) / 128.0f - 1.0f;
        }
        l->bias->matrix_ptr[i][0] = 0;
    }

    return l;
}

void stimulate_layer(struct matrix* m, struct layer** l)
{
    (*l)->input = m;
}

void run_layer(struct layer** l)
{
    if ((*l)->input == NULL) {
        return;
    }
    struct matrix* intermediary = NULL;

    // m = Wx
    matrix_multiply((*l)->weight, (*l)->input, &intermediary);

    // z = m + b
    matrix_add(intermediary, (*l)->bias, &intermediary);

    // y = f(z)
    matrix_apply_func(intermediary, (*l)->activation_func, &intermediary);

    // free the prior output
    free_matrix(&(*l)->output);
    // update the output
    (*l)->output = intermediary;
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