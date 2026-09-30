#include "matrix-utils.h"
#include <stdio.h>
#include <stdlib.h>

void free_matrix(struct matrix** m)
{
    if (*m == NULL)
        return;

    for (int i = 0; i < (*m)->rows; i++)
        free((*m)->matrix_ptr[i]);

    free((*m)->matrix_ptr);
    free((*m));

    // set the pointer to NULL to avoid use after free
    *m = NULL;
}

struct matrix* init_matrix(int r, int c)
{
    // attempt to make a new matrix
    struct matrix* m = malloc(sizeof(struct matrix));
    // not possible. Return NULL
    if (m == NULL) {
        return NULL;
    }

    // cannot have a matrix of 0 rows or 0 columns
    // because that makes no sense
    if (r == 0 || c == 0) {
        return NULL;
    }

    // else, possible. Assign row and columns
    m->rows = r;
    m->columns = c;

    // check if assigning number of rows (horizontal) is possible.
    // if not possible, free the earlier new_matrix
    if ((m->matrix_ptr = malloc(r * sizeof(float*))) == NULL) {
        free(m);
        return NULL;
    }

    // now make a loop to malloc the number of columns (vertical) per row
    for (int row = 0; row < r; row++) {
        // check if cannot allocate more space for number of columns
        if ((m->matrix_ptr[row] = malloc(c * sizeof(float))) == NULL) {
            free_matrix(&m);
            return NULL;
        }
    }

    return m;
}

// This prints the matrix in an
// ugly fashion to the terminal.
// Note: Ugly but works
void disp_matrix(struct matrix* m)
{
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < m->rows; i++) {
        printf("[%g", m->matrix_ptr[i][0]);
        for (int j = 1; j < m->columns; j++) {
            printf(", %g", m->matrix_ptr[i][j]);
        }
        printf("]\n");
    }
}

// This does Ab = y
void matrix_multiply(struct matrix* A, struct matrix* b, struct matrix** y)
{
    // first free result
    free_matrix(y);
    *y = NULL;

    // then answer the question.
    // to answer the question, we first need to check check that the matrix sizes are compatible
    if (A->columns != b->rows) {
        // and if it's not, set y to NULL
        *y = NULL;
        return;
    }

    // otherwise, now I gotta alloc a new thing for result.
    *y = init_matrix(A->rows, b->columns);
    if (*y == NULL) {
        return;
    }

    for (int j = 0; j < A->rows; j++) {
        for (int k = 0; k < b->columns; k++) {
            float sum = 0;
            for (int i = 0; i < A->columns; i++) {
                sum += A->matrix_ptr[j][i] * b->matrix_ptr[i][k];
            }
            (*y)->matrix_ptr[j][k] = sum;
        }
    }

    return;
}

void matrix_add(struct matrix* A, struct matrix* B, struct matrix** y)
{
    free_matrix(y);
    *y = NULL;

    // check if A and B are not the same dimensions, because if so, early return
    // it makes no sense to add the matrices otherwise
    if (A->columns != B->columns || A->rows != B->rows) {
        return;
    }

    // otherwise... Try to make a new matrix
    *y = init_matrix(A->rows, A->columns);

    // making a new matrix failed
    if (*y == NULL) {
        return;
    }

    // Do the adding here.
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            (*y)->matrix_ptr[i][j] = A->matrix_ptr[i][j] + B->matrix_ptr[i][j];
        }
    }

    return;
}

void matrix_multiply_scalar(struct matrix* A, float num, struct matrix** y)
{
    free_matrix(y);
    *y = NULL;

    // Try to make a new matrix
    *y = init_matrix(A->rows, A->columns);

    // making a new matrix failed
    if (*y == NULL) {
        return;
    }

    // Do the adding here.
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            (*y)->matrix_ptr[i][j] = A->matrix_ptr[i][j] * num;
        }
    }

    return;
}
