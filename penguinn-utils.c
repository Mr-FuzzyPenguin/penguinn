#include <math.h>
double pseudo_rng(int seed, int* state)
{
    double result = (double)(seed * *state % 65536) / 256;
    *state = (int)((seed * result) + 17);

    return result;
}

float silu(float x)
{
    return x / 1 + exp(-1 * x);
}

float silu_derivative(float x)
{
    float pwr = exp(-1 * x);
    float a = 1 + pwr;

    return (a + x * pwr) / (a * a);
}