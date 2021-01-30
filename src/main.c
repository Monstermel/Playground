#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "matrix.h"
#include "menu.h"
#include "newton.h"
#include "secante.h"


void portada(void) {
    puts("\n# Paquete de programas");
    puts("# Curso: Metodos numericos");
    puts("# Prof.: Teresa Carrillo Ramirez");
    puts("# Facultad De Estudios Superiores Acatlan");
    puts("\n# Integrantes:");
    puts("# Abreu Alvarez Jose Antonio");
    puts("# Avelar Alvarado Julio Cesar");
    puts("# Hernandez Garcia Luis Enrique");
    puts("# Salazar Silvero Rafael");
    puts("");

    system("pause");
    system("cls");
    return;
}
///////////////////////////////////////////////////////////////////////////
void (*metodo[])(unsigned) = {
    [1] = metodo_newton,
    [2] = metodo_secante,
};

void programa_1(void) {
    unsigned opc_1;  // Funcion a utilizar
    while (menu_funciones(&opc_1), system("cls"), opc_1 != 5) {
        unsigned opc_2;  // Metodo a utilizar
        while (menu_metodo(&opc_2, opc_1), system("cls"), opc_2 != 3) {
            metodo[opc_2](opc_1);
        }
    }
    return;
}
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void programa_2(void) {
    unsigned opc_1;
    size_t   dim        = 0U;
    double** buffer     = NULL;
    bool     show_solve = false;
    while (menu_ectn_slvr(&opc_1, show_solve), system("cls"), opc_1 != 4) {
        if (opc_1 == 1) {
            show_solve = read_matrix(&dim, &buffer);
        } else if (opc_1 == 2) {
            solve_mtrx(dim, buffer);
        } else if (opc_1 == 3) {
            solve_cholesky(dim, buffer);
        }
    }
    if (buffer != NULL) {
        for (size_t i = 0U; i < dim; i++) {
            free(buffer[i]);
        }
        free(buffer);
    }
    return;
}
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void programa_3(void) {
    system("cls");
    printf("\n# Digita la dimension de la matriz: ");
    size_t N;
    scanf("%zu%*c", &N);

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
    system("cls");

    printf("\n# Digite el numero maximo de iteraciones: ");
    size_t iteraciones;
    scanf("%zu%*c", &iteraciones);
    printf("# Digite la tolerancia: ");
    double tolerancia;
    scanf("%lf%*c", &tolerancia);
    printf("# Digite los elementos [i] del vector inicial: \n");
    double incl[N];
    double incl_aux[N];
    for (size_t i = 0; i < N; i++) {
        incl_aux[i] = 0.0;
        printf("# Digita el elemento [%zu]: ", i);
        scanf("%lf%*c", &incl[i]);
    }
    if (!(fabs(nrma_espctrl(N, incl, incl_aux) - 1.0) < __DBL_EPSILON__)) {
        puts("# La norma espectral es diferente de uno");
        system("pause");
        system("cls");
        return;
    };

    mtd_ptncs(N, matriz, iteraciones, tolerancia, incl);

    puts("");
    system("pause");
    system("cls");
    return;
}
///////////////////////////////////////////////////////////////////////////

void (*programa[])(void) = {
    [1] = programa_1,
    [2] = programa_2,
    [3] = programa_3,
};

int main(void) {
    portada();

    unsigned opc_1;
    while (menu_programa(&opc_1), system("cls"), opc_1 != 4) {
        programa[opc_1]();
    }

    return EXIT_SUCCESS;
}
