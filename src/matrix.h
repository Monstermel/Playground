#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#define _PRNT_MTRX(arr, rows, columns)           \
    for (size_t i = 0; i < (rows); i++) {        \
        printf("\t");                            \
        for (size_t j = 0; j < (columns); j++) { \
            printf("%.5lf  ", arr[i][j]);        \
        }                                        \
        puts("");                                \
    }

#define _LOAD_MTRX(arr, rows, columns)                         \
    for (size_t i = 0; i < (rows); i++) {                      \
        for (size_t j = 0; j < (columns); j++) {               \
            printf("# Digita el elemento [%zu][%zu]: ", i, j); \
            scanf("%lf%*c", &arr[i][j]);                       \
        }                                                      \
    }

#define _CPY_MTRX(arr, src, rows, columns)     \
    for (size_t i = 0; i < rows; i++) {        \
        for (size_t j = 0; j < columns; j++) { \
            arr[i][j] = src[i][j];             \
        }                                      \
    }
#define _MAX(a, b) ((a) < (b)) ? (b) : (a)
#include <stdlib.h>
#include <stdbool.h>

extern bool resolver;

void   read_matrix(void);
double determiant(size_t N, double arr[N][N]);
void   solve_mtrx(size_t N, double arr[N][N + 1]);
void   swap_row(size_t N, double arr[N][N], size_t i, size_t j);
void   swap_clmn(size_t N, double arr[N][N], size_t _i, size_t _j);

#endif  // MATRIX_H_INCLUDED
