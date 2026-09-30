double pseudo_rng(int seed, int* state)
{
    double result = (double)(seed * *state % 65536) / 256;
    *state = (int)((seed * result) + 17);

    return result;
}