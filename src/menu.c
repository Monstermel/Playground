#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

const char* fnctns[] = {
    [1] = "f(x) = (x^2)(cosx) - 2x",
    [2] = "f(x) = (6 - (2/x^2))(e^(2+x)/4) + 1",
    [3] = "f(x) = x^3 - 3sen(x^2) + 1",
    [4] = "f(x) = x^3 + 6x^2 + 9.4x + 2.5",
};

void menu_programa(unsigned* opc) {
    puts("\n# Seleccione el programa a ejecutar");
    puts("\t1) Metodo Newton/Secante");
    puts("\t2) Solucion de sistemas de ecuaciones");
    puts("\t3) Salir");

    while (printf("# [1,3]: "), read_opc(opc), (*opc) < 1 || 3 < (*opc)) {
        puts("# Opcion no valida");
    }
    return;
}

void menu_funciones(unsigned* opc) {
    puts("\n# Seleccione la ecuacion a resolver");
    puts("\t1) f(x) = (x^2)(cosx) - 2x");
    puts("\t2) f(x) = (6 - (2/x^2))(e^(2+x)/4) + 1");
    puts("\t3) f(x) = x^3 - 3sen(x^2) + 1");
    puts("\t4) f(x) = x^3 + 6x^2 + 9.4x + 2.5");
    puts("\t5) Salir");

    while (printf("# [1,5]: "), read_opc(opc), (*opc) < 1 || 5 < (*opc)) {
        puts("# Opcion no valida");
    }
    return;
}

void menu_metodo(unsigned* opc, unsigned fnctn) {
    printf("\n# Funcion a resolver: %s\n", fnctns[fnctn]);
    puts("# Seleccione metodo a usar");
    puts("\t1) Metodo de Newton");
    puts("\t2) Metodo de la Secante");
    puts("\t3) Salir");

    while (printf("# [1,3]: "), read_opc(opc), (*opc) < 1 || 3 < (*opc)) {
        puts("# Opcion no valida");
    }
    return;
}

void menu_ectn_slvr(unsigned* opc) {
    puts("\n# Seleccione una opcion");
    puts("\t1) Lectura de la matriz");
    puts("\t2) Salir");

    while (printf("# [1,2]: "), read_opc(opc), (*opc) < 1 || 2 < (*opc)) {
        puts("# Opcion no valida");
    }
    return;
}

void read_opc(unsigned* opc) {
    char bffr[100];
    scanf("%[^\n]%*c", bffr);
    (*opc) = (unsigned) (bffr[0] - '0');
    return;
}

void read_opc_size_t(size_t* opc) {
    char bffr[100];
    scanf("%[^\n]%*c", bffr);
    (*opc) = (size_t)(bffr[0] - '0');
    return;
}

void crtr_paro(unsigned* crtr) {
    puts("# Seleccione el criterio a usar");
    puts("\t1) Error absoluto");
    puts("\t2) Error relativo");
    puts("\t3) Error porcentual");

    while (printf("# [1,3]: "), read_opc(crtr), (*crtr) < 1 || 3 < (*crtr)) {
        puts("# Opcion no valida");
    }
    return;
}

void crrctn_mtrx(unsigned* opc, size_t N, size_t M, double arr[N][M]) {
    system("cls");
    printf("\n# Matriz:\n");
    for (size_t i = 0; i < N; i++) {
        printf("\t");
        for (size_t j = 0; j < M; j++) {
            printf("%.2lf  ", arr[i][j]);
        }
        puts("");
    }

    puts("# Correccion de matriz");
    puts("\t1) Corregir componente");
    puts("\t2) No corregir componente");

    while (printf("# [1,2]: "), read_opc(opc), (*opc) < 1 || 2 < (*opc)) {
        puts("# Opcion no valida");
    }
    return;
}
