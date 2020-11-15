#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "menu.h"
#include "newton.h"
#include "secante.h"

void (*metodo[])(unsigned) = {
    [1] = metodo_newton,
    [2] = metodo_secante,
};

void portada(void) {
    puts("\n# Programa 1");
    puts("# Curso: Metodos numericos");
    puts("# Prof.: Teresa Carrillo Ramirez");
    puts("# Facultad De Estudios Superiores Acatlan");
    puts("\n# Integrantes:");
    puts("# Abreu Alvarez Jose Antonio");
    puts("# Avelar Alvarado Julio Cesar");
    puts("# Hernandez Garcia Luis Enrique");
    puts("# Salazar Silvero Rafael");
    system("pause");
    system("cls");
    return;
}

int main(void) {
    portada();
    unsigned opc_1;  // Funcion a utilizar
    while (menu_funciones(&opc_1), system("cls"), opc_1 != 5) {
        unsigned opc_2;  // Metodo a utilizar
        while (menu_metodo(&opc_2, opc_1), system("cls"), opc_2 != 3) {
            metodo[opc_2](opc_1);
        }
    }
    return EXIT_SUCCESS;
}
