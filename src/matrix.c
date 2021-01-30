#include "matrix.h"

void swap_row(size_t N, double arr[N][N], size_t _i, size_t _j) {
    double aux[N];
    for (size_t i = 0; i < N; i++) {
        aux[i] = arr[_i][i];
    }
    for (size_t i = 0; i < N; i++) {
        arr[_i][i] = arr[_j][i];
    }
    for (size_t i = 0; i < N; i++) {
        arr[_j][i] = aux[i];
    }
    return;
}

void swap_clmn(size_t N, double arr[N][N], size_t _i, size_t _j) {
    double aux[N];
    for (size_t i = 0; i < N; i++) {
        aux[i] = arr[i][_i];
    }
    for (size_t i = 0; i < N; i++) {
        arr[i][_i] = arr[i][_j];
    }
    for (size_t i = 0; i < N; i++) {
        arr[i][_j] = aux[i];
    }
    return;
}

double determiant(size_t N, double arr[N][N]) {
    if (N == 1) {
        return arr[0][0];
    }
    double ans = 1.0;
    // Este for se desplaza por la diagonal
    for (size_t clmn = 0; clmn < N - 1; clmn++) {
        // Pivoteo total
        size_t i_max = clmn;
        size_t j_max = clmn;
        for (size_t i = clmn; i < N; i++) {
            for (size_t j = clmn; j < N; j++) {
                if (fabs(arr[i_max][j_max]) < fabs(arr[i][j])) {
                    i_max = i;
                    j_max = j;
                }
            }
        }
        if (clmn != i_max) {
            swap_row(N, arr, clmn, i_max);
            ans *= -1.0;
        }
        if (clmn != j_max) {
            swap_clmn(N, arr, clmn, j_max);
            ans *= -1.0;
        }
        // Este for se desplaza atravez de las filas
        for (size_t i = clmn + 1; i < N; i++) {
            // Aqui hacemos la suma de renglones
            double pvt = -(arr[i][clmn] / arr[clmn][clmn]);
            for (size_t j = 0; j < N; j++) {
                arr[i][j] = pvt * arr[clmn][j] + arr[i][j];
            }
        }
    }

    for (size_t i = 0; i < N; i++) {
        ans *= arr[i][i];
    }
    if (isnan(ans) || fabs(ans) < __DBL_EPSILON__) {
        return 0.0;
    }
    return ans;
}

double nrma_espctrl(size_t N, double x_0[N], double x_1[N]) {
    double aux[N];
    for (size_t i = 0; i < N; i++) {
        aux[i] = fabs(x_0[i] - x_1[i]);
    }

    double ans = aux[0];
    for (size_t i = 1; i < N; i++) {
        ans = _MAX(ans, aux[i]);
    }

    return ans;
}

bool is_EDD(size_t N, double arr[N][N]) {
    for (size_t i = 0; i < N; i++) {
        double aux_1 = fabs(arr[i][i]);
        double aux_2 = 0.0;
        for (size_t j = 0; j < N; j++) {
            if (i == j) continue;
            aux_2 += arr[i][j];
        }
        if (aux_1 <= aux_2) return false;
    }
    return true;
}

bool is_symmetric(size_t N, double arr[N][N]) {
    for (size_t i = 1; i < N; i++) {
        for (size_t j = 0; j < i; j++) {
            if (arr[i][j] != arr[j][i]) return false;
        }
    }
    return true;
}

void solve_cholesky(size_t N, double** arr) {
    system("cls");
    puts("");
    double mtrx[N][N];
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            mtrx[i][j] = arr[i][j];
        }
    }
    double inde[N];
    for (size_t i = 0; i < N; i++) {
        inde[i] = arr[i][N];
    }
    if (!is_symmetric(N, mtrx)) {
        puts("# No es una matriz simetrica\n");
        system("pause");
        system("cls");
        return;
    }
    double L_mtrx[N][N];
    memset(L_mtrx, 0, sizeof(L_mtrx));
    for (size_t i = 0; i < N; i++) {      // Columnas
        for (size_t j = i; j < N; j++) {  // Filas
            double aux = 0.0;
            for (size_t k = 0; k < j; k++) {
                aux += L_mtrx[j][k] * L_mtrx[i][k];
            }
            if (i == j) {
                L_mtrx[j][i] = sqrt(mtrx[j][i] - aux);
            } else {
                L_mtrx[j][i] = (mtrx[j][i] - aux) / L_mtrx[i][i];
            }
        }
    }
    unsigned opc = 2;
    do {
        if (opc == 1) {
            puts("\n# Digite los elementos [i] del vector independiente:");
            for (size_t i = 0; i < N; i++) {
                printf("# Digita el elemento [%zu]: ", i);
                scanf("%lf%*c", &inde[i]);
            }
            system("cls");
            puts("");
        }
        for (size_t i = 0; i < N; i++) {
            double aux = 0.0;
            for (size_t j = 0; j < i; j++) {
                aux += L_mtrx[i][j] * inde[j];
            }
            inde[i] = (inde[i] - aux) / L_mtrx[i][i];
        }
        for (ssize_t i = N - 1; 0 <= i; i--) {
            double aux = 0.0;
            for (ssize_t j = N - 1; i < j; j--) {
                aux += L_mtrx[j][i] * inde[j];
            }
            inde[i] = (inde[i] - aux) / L_mtrx[i][i];
        }
        puts("# Vector solucion:");
        for (size_t i = 0; i < N; i++) {
            printf("\t%.5lf\n", inde[i]);
        }
        puts("");
    } while (menu_ind(&opc), system("cls"), opc != 2);

    system("cls");
    return;
}

void solve_mtrx(size_t N, double** arr) {
    system("cls");
    puts("");
    double T_arr[N][N];
    double C_arr[N];
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            T_arr[i][j] = arr[i][j];
        }
    }
    for (size_t i = 0; i < N; i++) {
        C_arr[i] = arr[i][N];
    }

    if (!is_EDD(N, T_arr)) {
        puts("\n# La convergencia no se garantiza por no tratarse de un sistema EDD");
    }

    // Generamos la matris T y C
    for (size_t i = 0; i < N; i++) {
        double aux = T_arr[i][i];
        C_arr[i] /= aux;
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                T_arr[i][i] = 0.0;
                continue;
            }
            T_arr[i][j] = -(T_arr[i][j] / aux);
        }
    }

    // Aqui aplicamos Jacobi
    printf("# Digite el numero maximo de iteraciones: ");
    size_t iteraciones;
    scanf("%zu%*c", &iteraciones);
    printf("# Digite la tolerancia: ");
    double tolerancia;
    scanf("%lf%*c", &tolerancia);
    printf("# Digite los elementos [i] del vector inicial: \n");
    double ans_0[N];
    for (size_t i = 0; i < N; i++) {
        printf("# Digita el elemento [%zu]: ", i);
        scanf("%lf%*c", &ans_0[i]);
    }

    double ans_1[N];
    puts("");
    for (size_t itr = 0; itr < iteraciones; itr++) {
        for (size_t i = 0; i < N; i++) {
            ans_1[i] = 0;
            for (size_t j = 0; j < N; j++) {
                ans_1[i] += T_arr[i][j] * ans_0[j];
            }
        }
        for (size_t i = 0; i < N; i++) {
            ans_1[i] += C_arr[i];
        }
        double norma = nrma_espctrl(N, ans_0, ans_1);

        printf("# Iteracion %zu:\n", itr + 1);
        printf("# Error: %.6lf\n", norma);
        for (size_t i = 0; i < N; i++) {
            printf("  %.6lf\n", ans_1[i]);
        }
        puts("");
        if (itr + 1 == iteraciones) {
            puts("# Maximo de iteraciones alcanzado");
            break;
        }
        if (norma < tolerancia) {
            puts("# Tolarancia alcanzada");
            break;
        }

        for (size_t i = 0; i < N; i++) {
            ans_0[i] = ans_1[i];
        }
    }
    puts("# Vector solucion:");
    for (size_t i = 0; i < N; i++) {
        printf("  %.6lf\n", ans_1[i]);
    }
    puts("");
    system("pause");
    system("cls");
    return;
}

bool read_matrix(size_t* dim, double*** matrix) {
    printf("\n# Digita la dimension de la matriz: ");
    size_t N;
    scanf("%zu%*c", &N);
    // Leemos la matriz
    printf("\n# Digita los elementos [i][j] de tu matriz:\n");
    double matriz[N][N];
    _LOAD_MTRX(matriz, N, N);

    unsigned opc;
    while (crrctn_mtrx(&opc, N, N, matriz), opc != 2) {
        puts("# Ingresa la posicion [i][j] del elemento que deseas cambiar:");

        size_t i;
        while (printf("# i: "), read_opc_size_t(&i), N <= i) {
            puts("# Opcion no valida");
        }

        size_t j;
        while (printf("# j: "), read_opc_size_t(&j), N <= j) {
            puts("# Opcion no valida");
        }

        printf("# Ingresa el nuevo elemento: ");
        scanf("%lf%*c", &matriz[i][j]);
    }
    // Leemos el vector independiente
    system("cls");
    printf("\n# Digita los elementos [i] del vector indepentiende: \n");
    double ind[N][1];
    _LOAD_MTRX(ind, N, 1);

    while (crrctn_mtrx(&opc, N, 1, ind), opc != 2) {
        puts("# Ingresa la posicion [i] del elemento que deseas cambiar");

        size_t i;
        while (printf("# i: "), read_opc_size_t(&i), N <= i) {
            puts("# Opcion no valida");
        }

        printf("# Ingresa el nuevo elemento: ");
        scanf("%lf%*c", &ind[i][0]);
    }
    // Creamos la matriz ampliada
    system("cls");
    double ampld[N][N + 1];
    _CPY_MTRX(ampld, matriz, N, N);
    for (size_t i = 0; i < N; i++) {
        ampld[i][N] = ind[i][0];
    }
    puts("\n# Matriz ampliada: ");
    _PRNT_MTRX(ampld, N, N + 1);

    double dtrmnt = determiant(N, matriz);
    printf("\n# El determinante es igual a: %.5lf\n", dtrmnt);

    // Guardamos los datos recogidos
    if (*matrix != NULL) {
        for (size_t i = 0U; i < *dim; i++) {
            free((*matrix)[i]);
        }
        free(*matrix);
        *matrix = NULL;
    }
    *dim      = N;
    (*matrix) = (double**) malloc(N * sizeof(double*));
    for (size_t i = 0U; i < N; i++) {
        (*matrix)[i] = (double*) malloc((N + 1) * sizeof(double));
    }
    _CPY_MTRX((*matrix), ampld, N, N + 1);

    if (fabs(dtrmnt) < __DBL_EPSILON__) {
        puts("");
        system("pause");
        system("cls");
        return false;
    }
    puts("");
    system("pause");
    system("cls");
    return true;
}

void getCofactor(size_t N, double A[N][N], double temp[N][N], size_t p, size_t q, size_t n) {
    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return;
}

int determinant(size_t N, double A[N][N], size_t n) {
    double D = 0;
    if (n == 1) return A[0][0];
    double temp[N][N];
    double sign = 1.0;
    for (size_t f = 0; f < n; f++) {
        getCofactor(N, A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(N, temp, n - 1);
        sign = -sign;
    }
    return D;
}

void inverse(size_t N, double A[N][N]) {
    double det = determinant(N, A, N);
    double adj[N][N];
    if (N == 1) {
        adj[0][0] = 1.0;
    } else {
        double temp[N][N];
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                getCofactor(N, A, temp, i, j, N);
                adj[j][i] = (!((i + j) % 2) ? 1.0 : -1.0) * determinant(N, temp, N - 1);
            }
        }
    }
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            A[i][j] = adj[i][j] / det;
        }
    }
    return;
}

void mtd_ptncs(size_t N, double arr[N][N], size_t itr_max, double tlrnc, double incl[N]) {
    system("cls");
    puts("");
    double norm_aux[N];
    for (size_t i = 0; i < N; i++) {
        norm_aux[i] = 0.0;
    }
    double arr_cpy[N][N];
    memcpy(arr_cpy, arr, N * N * sizeof(double));
    bool snglr = !determiant(N, arr_cpy);

    double eigen_max = 0.0;
    double eigen_min = 0.0;
    double ini[N];
    for (size_t k = 0; k < 2; k++) {
        if (k == 0) {
            puts("# Eigen valor maximo:\n");
        } else {
            puts("# Eigen valor minimo:\n");
        }
        double eigen_0 = 0.0;
        memcpy(ini, incl, N * sizeof(double));
        for (size_t itr = 1; itr <= itr_max; itr++) {
            double aux[N];
            for (size_t i = 0; i < N; i++) {
                aux[i] = 0.0;
                for (size_t j = 0; j < N; j++) {
                    aux[i] += arr[i][j] * ini[j];
                }
            }
            double eigen_1 = nrma_espctrl(N, aux, norm_aux);
            for (size_t i = 0; i < N; i++) {
                ini[i] = aux[i] / eigen_1;
            }


            printf("# Iteracion %zu:\n", itr);
            puts("# Eigen vector:");
            for (size_t i = 0; i < N; i++) {
                printf("\t%lf\n", ini[i]);
            }
            printf("# Eigen valor: %lf\n", eigen_1);
            double error = tlrnc + 1.0;
            if (1 < itr) {
                error = fabs(eigen_1 - eigen_0);
                printf("# Error: %lf\n", error);
            }
            puts("");

            eigen_0 = eigen_1;

            if (error < tlrnc) {
                puts("# Tolerancia alcanzada");
                break;
            }
            if (itr_max < itr + 1) {
                puts("# Maximo de iteraciones alcanzado");
            }
        }

        if (k == 0) {
            inverse(N, arr);
            eigen_max = eigen_0;
        } else {
            eigen_min = 1.0 / eigen_0;
        }
        if (snglr) break;
        puts("");
        system("pause");
        puts("");
    }

    printf("# Eigen valor maximo: %lf\n", eigen_max);
    if (!snglr) {
        printf("# Eigen valor minimo: %lf\n", eigen_min);
    }
    return;
}