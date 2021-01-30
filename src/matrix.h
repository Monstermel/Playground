#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <math.h>
#include <stdint.h>
#include <string.h>

#include "menu.h"

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
#define ssize_t    long long



bool   read_matrix(size_t* dim, double*** matrix);
double determiant(size_t N, double arr[N][N]);
void   solve_mtrx(size_t N, double** arr);
void   solve_cholesky(size_t N, double** arr);
void   swap_row(size_t N, double arr[N][N], size_t i, size_t j);
void   swap_clmn(size_t N, double arr[N][N], size_t _i, size_t _j);
double nrma_espctrl(size_t N, double x_0[N], double x_1[N]);
void   mtd_ptncs(size_t N, double arr[N][N], size_t itr_max, double tlrnc, double incl[N]);

#endif  // MATRIX_H_INCLUDED
