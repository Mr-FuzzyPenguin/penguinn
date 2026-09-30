#include "matrix-utils.h"
#include "penguinn-utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int seed = 71;
    int state = 5129;

    struct matrix* A = init_matrix(2, 3);
    struct matrix* b = init_matrix(3, 5);

    struct matrix* result = NULL;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix_ptr[i][j] = (int)(pseudo_rng(seed, &state)) % 10;
        }
    }
    disp_matrix(A);

    puts("multiplied by...");

    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->columns; j++) {
            b->matrix_ptr[i][j] = (int)pseudo_rng(seed, &state) & 10;
        }
    }
    disp_matrix(b);

    matrix_multiply(A, b, &result);
    puts("=");
    disp_matrix(result);

    return 0;
}