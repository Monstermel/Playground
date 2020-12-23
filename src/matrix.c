//-Solicitar la dimensi�n n de la matriz y leerla, as� como el vector independiente.
//-Leer los coeficientes de la matriz (sean claros en la forma en que solicitan los datos).
//-Preguntar si los datos son correctos y si requiere corregir un coeficiente
//  pedir rengl�n y columna para corregir
#include "matrix.h"

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "menu.h"

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

void solve_mtrx(size_t N, double arr[N][N + 1]) {
    system("cls");
    double T_arr[N][N];
    double C_arr[N];
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < N; j++){
            T_arr[i][j] = arr[i][j];
        }
    }
    for(size_t i = 0; i < N; i++){
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

    double ans_0[4] = {};
    double ans_1[4];
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
        printf("# Error: %.5lf\n", norma);
        for (size_t i = 0; i < N; i++) {
            printf("  %.6lf\n", ans_1[i]);
        }
        puts("");

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
    return;
}

void read_matrix(size_t* _N, double**_arr) {
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

    *_N = N;
    _arr = (double*) realloc(_arr, )

    while (crrctn_mtrx(&opc, N, 1, ind), opc != 2) {
        puts("# Ingresa la posicion [i] del elemento que deseas cambiar");

        size_t i;
        while (printf("# i: "), read_opc_size_t(&i), N <= i) {
            puts("# Opcion no valida");
        }

        printf("# Ingresa el nuevo elemento: ");
        scanf("%lf%*c", &matriz[i][0]);
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

    if (fabs(dtrmnt) < __DBL_EPSILON__) {
        puts("");
        system("pause");
        system("cls");
        return;
    }

    char* msg =
        "\n# Solucion del sistema\n"
        "\t1) Si\n"
        "\t2) No\n"
        "# [1,2]: ";
    while (printf("%s", msg), read_opc(&opc), opc < 1 || 2 < opc) {
        puts("# Opcion no valida");
    }

    if (opc == 1) {
        solve_mtrx(N, ampld);
    }

    puts("");
    system("pause");
    system("cls");
    return;
}
