#ifndef PENGUINN_UTILS_H
#define PENGUINN_UTILS_H

struct rand {
    int seed;
    int state;
};

double pseudo_rng(struct rand* r);
float silu(float x);
float silu_derivative(float x);
#endif