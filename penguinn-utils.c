#include "penguinn-utils.h"
#include <math.h>
double pseudo_rng(int seed, int* state)
{
    double result = (double)(seed * *state % 65536) / 256;
    *state = (int)((seed * result) + 17);

    return result;
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