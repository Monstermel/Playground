#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

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

void (*metodo[])(unsigned) = {
    [1] = metodo_newton,
    [2] = metodo_secante,
};

void programa_1(void){
    unsigned opc_1;  // Funcion a utilizar
    while (menu_funciones(&opc_1), system("cls"), opc_1 != 5) {
        unsigned opc_2;  // Metodo a utilizar
        while (menu_metodo(&opc_2, opc_1), system("cls"), opc_2 != 3) {
            metodo[opc_2](opc_1);
        }
    }
    return;
}

void (*programa[])(void) = {
    [1] = programa_1,
    [2] = programa_1,
};

int main(void) {
    portada();

    unsigned opc_1;
    while (menu_programa(&opc_1), system("cls"), opc_1 != 3) {
        programa[opc_1]();
    }

    return EXIT_SUCCESS;
}
