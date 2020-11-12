#include <assert.h>
#include <stdlib.h>
#include <tgmath.h>

#include "menu.h"
#include "newton.h"

/*
    Nota:
    Talves se saquen de onda con los whiles, es algo que no nos enseñan en la carrea
    (que se me hace medio pendejo ya que es muy util), pero en C/C++ existe un operador
    especial, la coma: ",".
    por ejemplo: (expresion_1, expresion_2, expresion_3), si escribimos eso lo que el
    programa hara es evualar la expresion 1, luego la 2 y al final la 3, (puede ser caulquier
    tipo de instruccion) y regresara lo que regrese la ultima en ese caso la expresion 3.
*/

void (*metodo[])(unsigned) = {
    [1] = metodo_newton,
    //[2] = metodo_secante,
};

int main(void) {
    system("cls");
    unsigned opc_1;  // Funcion a utilizar
    while (menu_funciones(&opc_1), system("cls"), opc_1 != 5) {
        unsigned opc_2;  // Metodo a utilizar
        while (menu_metodo(&opc_2, opc_1), system("cls"), opc_2 != 3) {
            metodo[opc_2](opc_1);
        }
    }
    return EXIT_SUCCESS;
}
