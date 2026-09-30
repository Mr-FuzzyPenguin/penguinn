#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

struct matrix {
    unsigned int rows;
    unsigned int columns;
    float** matrix_ptr;
};

struct matrix* init_matrix(int r, int c);
void free_matrix(struct matrix** m);
void disp_matrix(struct matrix* m);
void matrix_multiply(struct matrix* A, struct matrix* b, struct matrix** y);
void matrix_add(struct matrix* A, struct matrix* B, struct matrix** y);
void matrix_multiply_scalar(struct matrix* A, float num, struct matrix** y);
#endif