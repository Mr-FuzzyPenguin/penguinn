#include "matrix-utils.h"
#include "penguinn-utils.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_STATE 5129
#define RANDOM_SEED 71

int main(void)
{
    struct rand r = { RANDOM_SEED, INITIAL_STATE };

    struct matrix* A = init_matrix(2, 3);
    struct matrix* b = init_matrix(3, 5);

    struct matrix* result = NULL;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix_ptr[i][j] = (int)(pseudo_rng(&r)) % 10;
        }
    }
    disp_matrix(A);

    puts("applied by SiLU...");

    // for (int i = 0; i < b->rows; i++) {
    //     for (int j = 0; j < b->columns; j++) {
    //         b->matrix_ptr[i][j] = (int)pseudo_rng(seed, &state) & 10;
    //     }
    // }
    // disp_matrix(b);
    //
    // matrix_multiply(A, b, &result);

    matrix_apply_func(A, silu, &A);
    puts("=");
    disp_matrix(A);

    return 0;
}